/*Given a sequence of words, check whether it forms a valid word square.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 =k < max(numRows, numColumns).

Note:

    The number of words given is at least 1 and does not exceed 500.
    Word length will be at least 1 and does not exceed 500.
    Each word contains only lowercase English alphabet a-z.
*/

/* leetcode lock this*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public: 
        bool validWordSquare(vector<string>& words) {
            string row,col; 
            for (unsigned int ri = 0; ri < words.size(); ++ri) {
                row = words.at(ri); 
                for (unsigned int ci = ri + 1; ci < row.size(); ++ci) {
                    if ( ci >= words.size() || ri >= words.at(ci).size() || row.at(ci) != words.at(ci).at(ri) ) {
                        return false; 
                    }
                }
            }
            return true; 
        }
};


int main(void) 
{
    Solution sol;
    vector<string> in1; 
    in1.push_back("abcd");
    in1.push_back("bnrt");
    in1.push_back("crmy");
    in1.push_back("dtye");
    
    cout << sol.validWordSquare(in1) << endl; 
    
    vector<string> in2; 
    in2.push_back("abcd"); 
    in2.push_back("bnrt");
    in2.push_back("crm");
    in2.push_back("dt");
    cout << sol.validWordSquare(in2) << endl; 

    vector<string> in3; 
    in3.push_back("ball");
    in3.push_back("area");
    in3.push_back("read");
    in3.push_back("lady");
    cout << sol.validWordSquare(in3) << endl; 
    
    return 0; 
}