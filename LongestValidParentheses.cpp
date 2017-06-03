/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/


#if 0 
// My initial thought has a short coming on below
// ) ()(()
// think about how it differ from )()()
class Solution {
public:
    void helper(string s, int nid, stack<char> &st, int &len, int &maxLen) {
      if (nid >= s.size()) return; 
      
      if (!st.empty()) {
        char nc = st.top();
        if (s.at(nid) == ')' && nc == '(') {st.pop(); len+=2;maxLen = max(maxLen, len);} 
        else if ( s.at(nid) == ')' && nc != '(') { maxLen = max(maxLen, len); len = 0; }
        else st.push(s.at(nid));
      } else {
        st.push(s.at(nid));
      }

      helper(s,nid+1, st, len, maxLen);
    }
    
    int longestValidParentheses(string s) {
      stack<char> st; 
      int len = 0, maxLen = 0; 
      helper(s, 0, st, len, maxLen); 
      return maxLen; 
    }
};

#endif 

// my thought: collapse a unit and keep track of unit length:
// stack has content like  ( unit unit ,
// if input is ), match with (, suppose each ( has start, then we know the length.
// 
// Then on the final stack, I just need to find out the max length of continuous units.  

#include <iostream>
#include <string>
#include <stack>

using namespace std;

#if 0
// The below pass LC OJ
// But it is so messy
// To improve:
// 1. ( with start is enough to calcuate the distance
// 2. How to avoid second pass? 
// 
// If stack
// 1. bottom store the last non match symbol's location
// 2. from bottom to top: store the not-yet matched '(' location
// Then it works:
//  1. initially, push -1 as the first non-match location
//  if incoming symbol is )
//     pop_stack
//     if stack is empty: no match, we push ) and its location in. This is new start
//     else stack top's location - current location is new length. update maxLen. 
//  else (incoming symbol is (
//     push ('s location in. 
class Solution {
public:
#if 0
    void printStack( stack<pair<char,int> > & st){
      while (!st.empty()) {cout << st.top().first << "," << st.top().second << endl; st.pop();}
    }
#endif     
    int longestValidParentheses(string s) {
      
      // if char = 'u", int is length
      // if char = '(' or ')', int is start location
      stack< pair<char,int> > st; 
      int maxLen = 0; 
      for (int i = 0; i < s.size(); ++i){
            int len = 0; 
            while (!st.empty() && st.top().first == 'u') {
              len += st.top().second; 
              st.pop();
            }
        
            bool isCharCollapsed = false; 
            if (!st.empty() && st.top().first == '(' && s.at(i) == ')') {
              len +=2;
              isCharCollapsed = true;
              st.pop();
            }
            if (len > 0) {maxLen = max(maxLen, len);st.push(make_pair('u',len));}
            if (!isCharCollapsed) {
              st.push(make_pair(s.at(i), i));
            }
            
      }
      
      // Then I need to do one traversal of stack to find out the longest consetive
      int nLen = 0; 
      while (!st.empty()) {
        if ( st.top().first == 'u' ) {
          nLen += st.top().second; 
          maxLen = max(maxLen, nLen);
        } else {
          nLen = 0; 
        }
        st.pop();
      }
      
      //printStack(st);
      
      return maxLen;
    }
};
#endif

class Solution {
  public:
  int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    
    int maxLen = 0; 
    for (int i = 0; i < s.size(); ++i){
      if (s.at(i) == '(') {st.push(i);}
      else {
        st.pop();
        if (st.empty()) {st.push(i);}
        else {int len = i - st.top(); maxLen = max(maxLen, len); }
      }
    }
    return maxLen; 
  }
};

int main(void)
{
  Solution sol;
  string s;
  
  s = ")()())";
  cout << s << " NUM =" << sol.longestValidParentheses(s) << endl;
  
  s = ")(()())";
  cout << s << " NUM =" << sol.longestValidParentheses(s) << endl;
  
  s = ")(()())(";
  cout << s << " NUM =" << sol.longestValidParentheses(s) << endl;

  s = ")(()()";
  cout << s << " NUM =" << sol.longestValidParentheses(s) << endl;
  return 0;
}
