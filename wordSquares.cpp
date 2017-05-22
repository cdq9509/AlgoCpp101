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

// This is HARD on leetcode

// brute force: find all permutations and then check whether it is valid word square. 
//            : actually, it is find all subset and then all permutation with subsets. 
// 
// I think the idea is actually similar as generation of set (also called backtracking):
// We use the following to prune out the failed ones:
//           suppose we start by picking at row 0, then it decides the prefix 0 for row 1
//                             so row K, it decides prefix 0 to K for row K + 1.  
//           a_0, a_1, a_2, a_3
//           a_1, b_1, b_2, b_3,..
//           a_2, b_2, c_2, c_3
// 
// basically, one half determs the other half

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

// I must use > > with a space inbetween, not >>

class Solution {
    private: 
        // Trie
        #define  TRIE_SZ 26       
        class Node{
        public:
            vector<Node*> children;
            vector<int> wordIndices;
            Node() { children.resize(TRIE_SZ, NULL);}
            ~Node()
            { 
                vector<Node*>::iterator it; 
                for (it = children.begin(); it != children.end(); ++it) {
                    if (*it != NULL) { delete *it; *it = NULL; }
                }
            }
        }; 
        
        Node *mRoot; // Root of trie
        void buildPrefixTbl( vector<string>& words ) {
            assert( 'z'-'a' + 1 == TRIE_SZ ); 
            for (unsigned int i = 0; i < words.size(); ++i) {
                string in = words.at(i);
                Node *root = mRoot; 
                root->wordIndices.push_back( i ); 
                for (unsigned int j = 0; j < in.size(); ++j) {
                        unsigned int ci = in.at(j) - 'a'; 
                        if (root->children.at(ci) == NULL) {
                            root->children.at(ci) = new Node; 
                        }
                        root->children.at(ci)->wordIndices.push_back( i ); 
                        root = root->children.at(ci); 
                }
            }
        }
        
        vector<int> getCandidateIndices( string& prefix, set<int>& resSet )        {
            Node *root = mRoot;
            cout << prefix << endl;
            vector<int> res; 
            
            for (unsigned int i = 0; i < prefix.size(); ++i) {
                unsigned int ci = prefix.at(i) - 'a';
                if ( root->children.at(ci) != NULL ) root = root->children.at(ci);
                else {return res;} 
            }
            for (unsigned int i = 0; i < root->wordIndices.size(); ++i) {
                unsigned int ind = root->wordIndices.at(i);
                if ( resSet.find( ind ) == resSet.end() ) { res.push_back(ind);}
            }
            return res; 
        }
        
        // Level indicates how many rows are already decided
        // 
        // by definition: we can check if whether 
        void helper( 
            vector<string>& words, // input  
            vector<string>& res, // populated up to level rows. 
            set<int>& resSet, // used word indices. To detect if a word is already used. 
            unsigned int level,  // row 0 to leve -1 is decided. we decide row level and up at this call. 
            unsigned int maxRow, // max number of rows. decided when first row is picked. 
            vector< vector<string> >& finalRes ) {
            
            if ( level >= maxRow ) {
                finalRes.push_back( res ); 
                return; 
            }
            
            assert( level >= 1 );
                        
            // Populate column level from row level to n
            string prefix = "";
            for (unsigned int i = 0; i < level; ++i) {
                prefix += res.at(i).at(level);
            }
            
            vector<int> candidateIndices = getCandidateIndices( prefix, resSet );
            
            for (unsigned int j = 0; j < candidateIndices.size(); ++j) {
                unsigned int ind = candidateIndices.at(j); 
                string candidate = words.at( ind );
                vector<string> tres = res; 
                tres.push_back( candidate );
                set<int> tresSet = resSet;
                tresSet.insert( ind );
                helper( words, tres, tresSet, level + 1, maxRow, finalRes ); 
            }
                        
            return; 
        }
        
    public:
        Solution() { mRoot = NULL; }
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
        
        vector<vector<string> > wordSquares( vector<string>& words ) {
            if ( mRoot != NULL ) { delete mRoot; mRoot = NULL; }
            mRoot = new Node; 

            buildPrefixTbl( words );
            
            // matrix of chars as word squares. 
            vector< vector<string> > finalRes; 
            for (unsigned int i = 0; i < words.size(); ++i) {
                string in = words.at(i);
                unsigned int maxRow = in.size();
                vector<string> res;
                set<int> resSet; 
                res.push_back(in);
                resSet.insert(i); 
                helper( words, res, resSet, 1, maxRow, finalRes ); 
            }
            
            { delete mRoot; mRoot = NULL; }
            return finalRes; 
        }
}; 

int main(void) 
{
    Solution sol; 

    cout << "Verify Recursive getSubsets is correct" << endl; 
    vector<string> in;
    in.push_back("ball");
    vector<vector<string> > res = sol.wordSquares( in );
    sol.print( res ); 
    
    in.push_back("area");
    res = sol.wordSquares( in );
    sol.print( res ); 

    in.push_back("lead");
    res = sol.wordSquares( in );
    sol.print( res ); 

    in.push_back("lady");
    res = sol.wordSquares( in );
    sol.print( res ); 
      
    return 0; 
}
