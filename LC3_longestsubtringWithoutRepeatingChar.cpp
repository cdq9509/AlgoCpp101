#include <iostream>
#include <string>
#include <map>

using namespace std;

// if use cout, will exceed timelimit

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, int> exist; 
        unsigned int maxLen = 0; 
        unsigned int j = 0 ; // Start pos
        unsigned int i = 0;  // End Pos
        for ( i = 0; i < s.size(); i++ ) {
            if ( exist.find(s[i]) == exist.end() ) {
                exist[ s[i] ] = i; 
                    cout << "First" << i <<", " << j << endl; 
            } else {
                if ( exist[s[i]] != -1 ) {
                    int newLoc = exist[ s[i] ]; // New location 
                    for ( int k = j; k < newLoc; k ++ ) {
                        exist[ s[k] ] = -1; 
                    }
                    j = newLoc + 1; 
                    exist[ s[i] ] = i ; 
                    cout << "Second" << i <<", " << j << endl; 
                    
                } else {
                    exist[s[i]] = i; 
                    cout << "Third" << i <<", " << j << endl; 

                }
            }
            maxLen = max ( maxLen, i - j + 1 ); 

        }
        
        return maxLen; 
    }
};

int main(void)
{
    Solution sol; 
    // string s = "abcabcbb";
    string s = "abba"; 
    cout << s << endl;
    cout << "len:" << endl;
    cout << sol.lengthOfLongestSubstring(s) << endl; 
}