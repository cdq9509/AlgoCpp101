#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    string convert(string s, int numRows) {
        unsigned int r = 0; // current row 
        unsigned int i = 0; // idx 
        unsigned int j = 0; 
        unsigned int step = numRows + numRows - 2 ; 
        if ( step == 0 ) return s; 
        string ret;
        ret.resize( s.size() ) ; 
        while ( i < s.size() ) {
            j = r;  // Every row starts at row number
            while ( j < s.size() ) {
                
                // First element
                ret[i++] = s[j]; 
                // cout << ret[i-1] << "," << r << "," << i << "," << j << endl; 
                j += step;
                
                // Second element
                if ( r != 0 && r != (unsigned int) (numRows - 1) ) {
                    unsigned int j2 = j - step; // Second element offset from first element
                    j2 += numRows - r -1 +  (numRows - r - 1); 
                                               // Reverse direction: plus (numRows - r - 1) to arrive at bottom
                                               //                    plus (numRows - r - 1) 
                    
                    if ( j2 < s.size() ) {
                        ret[i++] = s[j2]; 
                        // cout << ret[i-1] << "," << r  << "," << i << "," << j2 << "#2" << endl; 
                    }
                }
            }
            r++; 
        }
        
        return ret; 
        
    }
};

int main(void)
{
    Solution sol; 
    string s = "PAYPALISHIRING";
    cout << sol.convert(s, 3) << endl; 
    
    s = "A";
    cout << sol.convert(s, 1) << endl;

    s = "AB";
    cout << sol.convert(s, 1) << endl; 
    
    s = "ABCDE";
    cout << sol.convert(s, 4) << endl; 
 
    s = "PAYPALISHIRING";
    cout << sol.convert(s, 4) << endl; 
     
}