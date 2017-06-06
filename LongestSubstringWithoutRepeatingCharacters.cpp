/* Longest Substring Without Repeating Characters 
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <string>
#include <map>
using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> subset; // int is location so that we update
        
        int maxSize = 0, curSize = 0, start = 0; 
        for (int i = 0; i < s.size(); ++i) {
          if (subset.find(s.at(i)) == subset.end()) { 
            
            subset[s.at(i)] = i; 
            curSize = i - start + 1;
          } 
          else { 
            if (subset[s.at(i)] >= start) start = subset[s.at(i)] + 1; 
            curSize = i - start + 1; 
            subset[s.at(i)] = i; 
          }
          
          maxSize = max(maxSize, curSize);
        }
        return maxSize; 
    }
};

int main(void)
{
  string s;
  Solution sol;
  
  s = "abba";
  cout << s << " Len" << sol.lengthOfLongestSubstring(s) << endl;
  
  s= "abcda";
  cout << s << " Len" << sol.lengthOfLongestSubstring(s) << endl;
  
}