#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxhere = INT_MIN;
        long long maxsofar = INT_MIN; 
        
        vector<int>::iterator i; 
        for( i = nums.begin(); i != nums.end(); i++ ) {
            maxhere = max( maxhere + *i, maxhere );
            maxsofar = max( maxsofar, maxhere ); 
        }
        
        
    }
};