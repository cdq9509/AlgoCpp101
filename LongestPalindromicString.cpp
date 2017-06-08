/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"

*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      vector<vector<bool> > LPS; // LPS[i][j]: is [i,j] palindrome. 
      int n = s.size();
      LPS.resize(n);
      for (int i = 0; i < n; ++i) { LPS.at(i).resize(n); }
      
      // Initialization: palindrom size of itself is 1
      for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
          LPS.at(i).at(j) = 1; 
        }
      }
      
      int maxLen = 0, maxStart = 0;
      for (int end = 0; end < n; ++end) { // end point
        for (int start = end; start >= 0; --start) {
          if (start == end) LPS.at(start).at(end) = true;
          else if ( end = start + 1 ) LPS.at(start).at(end) = (s.at(end) == s.at(start));
          else if ( LPS.at(start+1).at(end-1) && s.at(end) == s.at(start) ) LPS.at(start).at(end) = true; 
          
          if (LPS.at(start).at(end)) {
            int len = end - start + 1; 
            if (maxLen < len) { maxLen = len; maxStart = start;}
          }
        }
      }
      return s.substr( maxStart, maxLen );
        
    }
};

int main(void)
{
  Solution sol; 
  string s;
  
  s = "a";
  cout << "In:" << s << " LPS:" << sol.longestPalindrome(s) << endl;

  s = "ab";
  cout << "In:" << s << " LPS:" << sol.longestPalindrome(s) << endl;

  s = "aba";
  cout << "In:" << s << " LPS:" << sol.longestPalindrome(s) << endl;
  
  return 0;
}