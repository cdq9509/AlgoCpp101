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
      for (int e = 0; e < n; ++e) { // end point
        for (int s = e; s >= 0; --s) {
          if (s == e) LPS.at(s).at(e) = true;
          else if ( e = s + 1 ) LPS.at(s).at(e) = (s.at(e) == s.at(i));
          else if ( LPS.at(s+1).at(e-1) && s.at(e) == s.at(i) ) LPS.at(s).at(e) = true; 
          
          if (LPS.at(s).at(e)) {
            int len = e - s + 1; 
            if (maxLen < len) { maxLen = len; maxStart = s;}
          }
        }
      }
      return s.substr( maxStart, maxLen );
        
    }
};