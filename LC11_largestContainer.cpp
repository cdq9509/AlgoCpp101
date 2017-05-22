#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Sort of greedy approach with the following observation:
        // say we start with 0, N
        // if h[0] < h[N], then h[0], h[N-1] is bounded to have smaller area with h[0], h[N]
        //                 bec min( h[0], h[N-1] ) <= h[0] 
        unsigned int l = 0;
        unsigned int r = height.size() - 1; 
        unsigned int area = 0; 
        unsigned int tmp = 0; 
        while ( l != r ) {
            tmp = ( r - l ) * min( height[l], height[r] );
            area = max( tmp, area ); 
            if ( height[l] < height[r] ) {
                l++; 
            } else {
                r--; 
            }
        }
        
        return area; 
    }

    // exhaustive method: exceed time limit
    int maxArea2(vector<int>& height) {
    
        unsigned int n = height.size(); 
        unsigned long long area = 0; 
        for (unsigned int i = 0; i < n; i++ ) {
            for (unsigned int j = i + 1; j < n; j++ ) {
                    unsigned long long temp = ( j - i ) * min( height[j] , height[i]);
                    area = max( temp, area ); 
                
            }
        }
        
        return area; 
    }
};
