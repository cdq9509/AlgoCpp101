#include <iostream>
#include <string>
#include <map>

using namespace std; 

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman; 
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;
        
        int res = 0; 
        for ( unsigned int i = 0; i < s.size(); i++  ) {
           
            int si = roman[ toupper( s[i] ) ]; 
            int si1 = 0; 
            if ( (i+1) < s.size() ) { 
                si1 = roman[ toupper( s[i+1] ) ]; 
                if (  si >= si1  ) {
                    res += si; 
                } else {
                    res -= si; 
                }
            } else {
                res += si; 
            }
            // cout << si << "," << si1 << "," << res << endl; 
        }
        return res; 
    }
};

int main(void)
{
    string s;
    Solution sol;
    
    s = "xvi"; 
    cout << s << "," << sol.romanToInt( s ) << endl; 
    
}
