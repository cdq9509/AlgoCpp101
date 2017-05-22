#include <iostream>
#include <climits>


// Start time: 11:37 am
// Compile time: (local compilation/pass): 12:17. Thers is a fundamental flaw. Rewrite after checking web. f
// End time (pass LC OJ):  
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
      if ( x < 0 ) return false; // negative number no palindrome
      
      // First we need to know the number of digit to compare
      // This will prevent case such as 1000023 to pass through
      int div = 1;
      int y = x; 
      while ( y / 10 ) {
        div *= 10; 
        y =  y / 10; 
      }
      
      int top, bot = 0; // top digit
      while ( x ) {
        top = x / div; 
        bot = x % 10 ; 
        
        if ( top != bot ) return false; 
        
        x = ( x - top * div ) / 10 ; // update the number
        div = div / 100; // update divide base
      }
 
      return true; 
    } 
};


#if 0 
  
    // This does not work
    bool isPalindrome2(int x) {
      if ( x < 0 ) return false; // negative number no palindrome
      // First we need to know the number of digit to compare
      // This will prevent case such as 1000023 to pass through
      
      while ( x > 0 ) {
        // cout << x << endl; 
        int rem = x % 10 ;  // last digit
        int y = x; 
        int w = 1; 
        while ( ( y / 10 )  !=  0 ) {
            y = y / 10 ; 
            w = w * 10 ; 
        } 
        int ld = y;  // first digit
        x = ( x - ld * w - rem ) / 10; // updated number to be compared against;  
        if ( rem != ld ) {
          return false; 
        } 
 
      }
        
      return true; 

    }

#endif 
int main(void) 
{
     Solution sol; 
     
     int x = 1234;
     cout << x << ", " << sol.isPalindrome(x) << endl; 
    
     x = 1; 
     cout << x << ", " << sol.isPalindrome(x) << endl; 
     
     x = 121; 
     cout << x << ", " << sol.isPalindrome(x) << endl; 
    
     x = 1221; 
     cout << x << ", " << sol.isPalindrome(x) << endl; 
     
     x = 12321; 
     cout << x << ", " << sol.isPalindrome(x) << endl; 

     x = 1000021;
     cout << x << ", " << sol.isPalindrome(x) << endl; 
     
    return 0; 
}