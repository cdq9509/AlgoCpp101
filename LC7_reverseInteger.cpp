#include <iostream>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        queue<int> s; 
        do {
            s.push( x % 10 ) ; 
            x = x / 10 ; 
        } while  ( x != 0 ) ;
        
        long long ret = 0; 
        do {
            ret *= 10; 
            ret += s.front(); 
            cout << s.front() << "," << ret << endl; 
            s.pop(); 
        } while ( ! s.empty() ); 
        
        if ( ret > INT_MAX || ret < INT_MIN ) return 0; 
        else return ret; 
    }
};

int main(void) 
{
    int s; 
    Solution sol; 
    
    s = 123;
    cout << sol.reverse( s) << endl; 

    s = -123;
    cout << sol.reverse( s) << endl; 
    
    s = 1534236469; 
    cout << sol.reverse( s) << endl; 
    
}