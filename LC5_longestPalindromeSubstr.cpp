#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    int palindromeLen( string s, int c ) {
        // First compute if center at c
        int i = c -1 ; 
        int j = c + 1; 
        int clen = 1; 
        while ( i >= 0 && j < (int) s.size() ) {
            if ( s[i] == s[j] ) {
                clen += 2 ;
            } else {
                break; 
            }
            i--;
            j++; 
        }
        
        // Second, compute if it is even length of Palindrome ( c and c + 1 )
        i = c ; 
        j = c + 1; 
        int elen = 0; 
        while ( i >= 0 && j < (int) s.size() ) {
            if ( s[i] == s[j] ) {
                elen += 2 ;
            } else {
                break; 
            }
            i--;
            j++; 
        }
        return max(clen, elen); 
    }
    
    string longestPalindrome(string s) {
        int maxLen = 0; 
        int loc = 0; 
        for ( int i = 0; i < (int) s.size() ; i++ ) {
            // Length of palindrom center at index i OR (i, i + 1 )
            int len  = palindromeLen( s, i ); 
            if ( maxLen < len ) {
                loc = i; 
                maxLen = len; 
            }
        }
        cout << maxLen << endl; 
        int l = 0;
        int r = 0;
        if (maxLen & 0x1) {
            l = loc - (maxLen - 1)/2;
            r = loc + (maxLen - 1)/2; 
        } else {
            l = loc - maxLen/2 + 1;
            r = loc + maxLen/2; 
        }
        
        return s.substr( l, r - l + 1); 
    }
};

int main(void)
{
    // string s = "a";
    string s = "bb";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl; 
    return 0 ; 
}