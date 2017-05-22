#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Recursive approach 
    bool isMatch(string s, string p) {
        /*cout << "1#" << s << endl; 
        cout << "2#" << p << endl; 
        */
        // Ending conditions
        
        // no more patterns to match
        if ( p.size() == 0 ) {
            return ( s.size() == 0 ) ; 
        }
        
        // only one pattern char left
        if ( p.size() == 1 ) {
            if ( ( s.size() == 1 &&  ( s[0] == p[0] || p[0] == '.' ) ) ) return true; 
            else return false; 
        }
        
        // More generic
        if ( p[1] != '*' )  {
            if ( (s[0] != p[0] && p[0] != '.') || s.size() < 1 ) return false; 
            else return isMatch(s.substr( 1 ), p.substr( 1 ) ); 
        } else  { 
            // for p[1] == '*'
            
            // Try to see if x* can be ignored. 
            if ( isMatch( s.substr(0), p.substr(2) ) ) {
                return true; 
            } 
            
            // if x* cannot be ignored, 
            if ( ( s.size() >= 1) &&  ( s[0] == p[0] || p[0] == '.' ) ) {
                return isMatch( s.substr( 1 ) , p.substr( 0 ) ); // s[0] matched
            } else {
                return false; // s[0] not matched. we see if 
            }
        }
    }
};

int main(void)
{
    Solution sol; 
    string s, p;
    
    s = "aa";
    p = "a";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
    
    s = "aaa";
    p = "a*";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
    
    s = "aab";
    p = "c*a*b";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
    
    s = "ab";
    p = ".*";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
    
    s = "aaa"; 
    p = "a*a";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
    
    s = "ab"; 
    p = ".*c";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
  
    s = "a"; 
    p = ".";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
  
    s = "a"; 
    p = "ab*";
    cout << s << "," << p << "," << sol.isMatch(s, p ) << endl; 
    
    return 0 ; 
}