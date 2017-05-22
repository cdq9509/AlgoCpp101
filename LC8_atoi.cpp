#include <iostream>
#include <string>
#include <climits>


// Start time: 10:37 am
// Compile time: (local compilation/pass): 11:02 (waste some time in cchere). coding time is really just 15 min
// End time (pass LC OJ): 11:35 am. 
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool start = false; 
        long long ret = 0; 
        int sign = 1; 
        for (unsigned int i = 0; i < str.size(); i++ ) {
            char c = str[i]; 

            // Only white space, +, -, number at first
            if (!start) {
                if ( c ==  ' ' ) {
                    continue;
                } else if ( c == '+' ) {
                    start = true; 
                    sign = 1; 
                    continue; 
                } else if ( c == '-' ) {
                    start = true; 
                    sign = -1; 
                        continue; 
                } else if ( c >= '0' && c <= '9') {
                    start = true;
                    sign = 1; 
                } else {
                    return 0; 
                }
            }
                        
            // Handle all number
            if ( c >= '0' && c <= '9' && start) {
                ret *= 10; 
                // overflow
                ret += ( c - '0' ); 
                if ( sign * ret > INT_MAX ) return INT_MAX; 
                if ( sign * ret < INT_MIN ) return INT_MIN; 

            } 
            
            // Once starts, we ends with non-integer char
            if ( start && ( c < '0' || c > '9' ) ) {
                break; 
            }
            
        }
        
        ret = sign*ret; 
        
        return ret; 
        
    }
};

int main(void) 
{
    string s;
    Solution sol; 
    
    s = "+123";
    cout << sol.myAtoi(s) << endl; 
    
    s = "+-2"; // expect 0 
    cout << sol.myAtoi(s) << endl; 

    s = "  -0012a42"; // expect - 12
    cout << sol.myAtoi(s) << endl; 

    s = " -2147483648"; // expect "-2147483648"
    cout << sol.myAtoi(s) << endl; 

    s = " 2147483648"; // expect "2147483648"
    cout << sol.myAtoi(s) << endl; 
    
    s = " b11228552307"; // expect 0
    cout << sol.myAtoi(s) << endl; 
    
    s = "9223372036854775809"; // xpected: 2147483647 
    cout << sol.myAtoi(s) << endl; 

    return 0; 
}