/* Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 = k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y

Note:

    There are at least 1 and at most 1000 words.
    All words will have the exact same length.
    Word length is at least 1 and at most 5.
    Each word contains only lowercase English alphabet a-z.
*/

// brute force: find all permutations and then check whether it is valid word square. 
//            : actually, it is find all subset and then all permutation with subsets. 
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// I must use > > with a space inbetween, not >>

class Solution {
    public:
        bool validWordSquares( vector<string>& words ) {
            return false; 
        }
        
        void print( vector< vector<string> >& in ) {
            cout << "########## total "<< in.size() << "################" << endl; 
            for (unsigned int i = 0; i < in.size(); ++i) {
                vector<string> words = in.at(i); 
                for(unsigned j = 0; j< words.size(); ++j) {
                    cout << words.at(j) << ","; 
                }
                cout << endl; 
            }
        }
        
        // MY concern on memory leadk seems to be invalid.
        // return vector is fine ( in theory, when returning, there is a copy happening. In practicse, compiler may optimize it out).
        // Also, vector does copy when assignmened. So it is ok. 
        // The following function is done in 30 min and looks correct.
        // Note that it does not generate the empty set in the final. so the total size = 2 ^ n - 1.
        //           if including all empty set, the total size would be 2 ^ n.
        // 
        // Note that it use recursion. // Is it easy to use iterations?  
        // What is complexity: n^2 ?? 
        vector< vector<string> > getSubsets( vector<string>& words ) {
            vector< vector<string> > finalRes; 
            if (words.size() <= 1) {
                finalRes.push_back( words ); 
                return finalRes; 
            }
            vector<string> in = words;
            string elem = in.back(); 
            in.pop_back();
            vector<vector<string> > res = getSubsets( in );
            // now combine 
            for (unsigned int j = 0; j < res.size(); ++j) {
                vector<string> t = res.at(j);
                // subset
                finalRes.push_back( t );                    
                // subset + elem
                t.push_back(elem);
                finalRes.push_back( t ); 
            }
            // elem itself is a set too
            vector<string> t;
            t.push_back(elem);
            finalRes.push_back( t ); 
            
            return finalRes; 
        }

        // Iterative version of get subsets
        vector< vector<string> > getSubsetsIterative( vector<string>& words ) {
            stack< string > s;
            vector<string> in = words;
            while (in.size() > 1) {
                string elem = in.back();
                in.pop_back();
                s.push( elem );
            }
            assert( in.size() <= 1 ); 
            vector< vector<string> > res, finalRes;
            res.push_back( in );
            while ( !s.empty() ) {
                string elem = s.top(); 
                s.pop();
                finalRes.resize(0); 
                
                for (unsigned int j = 0; j < res.size(); ++j) {
                    vector<string> t = res.at(j);
                    // subset
                    finalRes.push_back( t );                    
                    // subset + elem
                    t.push_back(elem);
                    finalRes.push_back( t ); 
                }
                // elem itself is a set too
                vector<string> t;
                t.push_back(elem);
                finalRes.push_back( t ); 
                
                // Keep the last run's value
                res = finalRes; 
            }
            return res; 
        }
        
        // Get all permutations 
        // number of permuation is n!.
        // Now sterlin's formula: n! --> (n)^n
        // Intuitive way to understand it: 
        //          n! eventually grows faster than an exponential with a constant base (2^n and e^n), 
        //          but n^n grows faster than n! since the base grows as n increases.
        vector< vector<string> > getPerm( vector<string>& words ) {
            vector< vector<string> > finalRes;
            if (words.size() <= 1) {
                finalRes.push_back(words);
                return finalRes; 
            }
            
            string elem = words.back();
            vector<string> in = words;
            in.pop_back();
            vector< vector<string> > res = getPerm( in );
            
            for (unsigned int j = 0; j < res.size(); ++j) {
                // insert elem from 0 to size - 1
                vector<string> t = res.at(j);
                for (unsigned int k = 0; k < t.size(); ++k) {
                    vector<string> tt = t; 
                    tt.insert( tt.begin() + k, elem ); 
                    finalRes.push_back( tt ); 
                }
                // insert at end
                vector<string> tt = t; 
                tt.push_back( elem ); 
                finalRes.push_back( tt ); 
            }            
            return finalRes; 
        }

        // Iterative get all permuations
        vector< vector<string> > getPermIterative( vector<string>& words ) {
           
            stack< string > s; // stack
            string st;  // stack top

            vector<string> in = words; 
            while ( in.size() > 1 ) {
                st = in.back(); 
                in.pop_back(); 
                s.push(st);
            }
            assert( in.size() <= 1 ); 
            
            vector< vector<string> > finalRes, res;

            res.push_back( in ); 

            while ( !s.empty() ){
                st = s.top();
                s.pop(); 
                finalRes.resize(0);
                for (unsigned int j = 0; j < res.size(); ++j) {
                    // insert elem from 0 to size - 1
                    vector<string> t = res.at(j);
                    for (unsigned int k = 0; k < t.size(); ++k) {
                        vector<string> tt = t; 
                        tt.insert( tt.begin() + k, st ); 
                        finalRes.push_back( tt ); 
                    }
                    // insert at end
                    vector<string> tt = t; 
                    tt.push_back( st ); 
                    finalRes.push_back( tt ); 
                } 

                // save for next iteration
                res = finalRes; 
            }           
            return res; 
        }

        
        vector<vector<string> > wordSquares( vector<string>& words ) {
            vector<vector<string> > sets = getSubsets( words ); 
            return sets; 
        }
}; 

int main(void) 
{
    Solution sol; 

    /** Verify Recursive getSubsets is correct **/
    cout << "Verify Recursive getSubsets is correct" << endl; 
    vector<string> in;
    in.push_back("ball");
    vector<vector<string> > res = sol.getSubsets( in );
    sol.print( res ); 
    
    in.push_back("area");
    res = sol.getSubsets( in );
    sol.print( res ); 

    in.push_back("lead");
    res = sol.getSubsets( in );
    sol.print( res ); 

    in.push_back("lady");
    res = sol.getSubsets( in );
    sol.print( res ); 
    
    /** Verify Iterative getsubsets is correct **/
    in.resize(0);
    cout << "Verify Iterative getSubsets is correct" << endl; 
    in.push_back("ball");
    res = sol.getSubsetsIterative( in );
    sol.print( res ); 
    
    in.push_back("area");
    res = sol.getSubsetsIterative( in );
    sol.print( res ); 
   
    in.push_back("lead");
    res = sol.getSubsetsIterative( in );
    sol.print( res ); 

    /** Verify Recursive getPerm is correct **/
    in.resize(0);
    cout << "Verify Recursive getPerm is correct" << endl; 
    in.push_back("ball");
    res = sol.getPerm( in );
    sol.print( res ); 
    
    in.push_back("area");
    res = sol.getPerm( in );
    sol.print( res ); 
   
    in.push_back("lead");
    res = sol.getPerm( in );
    sol.print( res ); 

    in.push_back("lady");
    res = sol.getPerm( in );
    sol.print( res ); 
    
    /** Verify Iterative getPerm is correct **/
    in.resize(0);
    cout << "Verify Iterative getPerm is correct" << endl; 
    in.push_back("ball");
    res = sol.getPermIterative( in );
    sol.print( res ); 
    
    in.push_back("area");
    res = sol.getPermIterative( in );
    sol.print( res ); 
   
    in.push_back("lead");
    res = sol.getPermIterative( in );
    sol.print( res ); 

    in.push_back("lady");
    res = sol.getPermIterative( in );
    sol.print( res ); 
    
    return 0; 
}
