/* This shows up in Amazon online test.  I don't understand that question first.
Turns out this is LC 438. I thought about the following basic idea on saturday:


1. Linear scan the haystack string, use sum as the first filter. O(N)
2. One find a candidate set, sort them and if the sorted is equal to sorted input, then it is a anangram
2.a  this is o(klog(k))
2.b at this moment, this is O(NKlog(K))
2.c. But we are removing one from a known sorted sequence and insert one to a known sorted sequence
2.d. so we dont need to sort every single time. Use insertion to a sorted array. This should give us 
2.d  log(K). But it is not O(Nlog(K), because we need to swap.
2.e. Well, wait, we can use merge idea here. It would be just K 
2.f. So I get a O(NK)

Now think about brute force:
0. for input string of size k, candidate size is K factorial. (building a data base of this would be too much)
1. linear scan
2. for each k, find all anaga

I cheat and use sort. Wow. this is an easy, but I spent 1 hour and exceed timeline!!!!!!!!!!!
Can just use count table. 
*/
/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  private:
  typedef unsigned long uint32;
    uint32 preproc( string &p ) {
      // sort input
      sort(p.begin(), p.end());
      // calculate input's hash sum
      uint32 hash_sum = 0;
      for (string::iterator it = p.begin(); it != p.end(); ++it) {
        hash_sum += (*it);
      }
      // cout << hash_sum << endl;
      return hash_sum;
    }
  public:  
    void printVec( vector<int> res ) {
      cout << "[";
      for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << (*it) << ",";
      }
      cout << "]";
      cout << endl;
    }
    vector<int> findAnagrams(string s, string p) {
      uint32 n = s.size();
      uint32 k = p.size();
      vector<int> res; 
      
      if ( n < k ) return res; 
      uint32 target_hsum = preproc(p);
      
      string zstr = s.substr(0, k);
      uint32 hsum = preproc(zstr);
        if (hsum == target_hsum && zstr == p ) {
          res.push_back(0);
        }
      
      
      int i,j; // j start_pos; i:next end pos 
      for (i = k-1, j = 0; i < n-1; ++i, ++j) {
        uint32 replace_pos = zstr.find(s.at(j));
        zstr.at(replace_pos) = s.at(i+1);
        uint32 hsum = preproc(zstr);
        //cout << zstr << "," << p << endl;
        if (hsum == target_hsum && zstr == p ) {
          res.push_back(j+1);
        }
      }
      //printVec(res);
      return res;
    }    
};

int main(void)
{
  string s, p;
  vector<int> res;
  Solution sol;
  
  p = "abc";
  s = "cbaebabacd";
  res = sol.findAnagrams(s,p);
  
  s = "abab";
  p = "ab";
  res = sol.findAnagrams(s,p);
  
  return 0;
}