#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // http://blog.csdn.net/zxzxy1988/article/details/8587244
    // if odd, find n1 st. nums1[n1]
    // not finshed. 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for (unsigned int i = 0; i < nums1.size(); i ++ ) {
            nums.push_back( nums1[i] );
        }
        for (unsigned int i = 0; i < nums2.size(); i ++ ) {
            nums.push_back( nums2[i] );
        }
        
        sort( nums.begin(), nums.end() ); 
        int tsize = nums1.size() + nums2.size(); 
        
        if ( tsize & 0x1 ) {
            return 1.0*nums[ ( tsize - 1 )/2 ]; 
            
        } else {
            return (1.0 * nums[ tsize/2 ] + 1.0 * nums[ tsize/2 - 1 ])/2.0; 
        }
        
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for (unsigned int i = 0; i < nums1.size(); i ++ ) {
            nums.push_back( nums1[i] );
        }
        for (unsigned int i = 0; i < nums2.size(); i ++ ) {
            nums.push_back( nums2[i] );
        }
        
        sort( nums.begin(), nums.end() ); 
        int tsize = nums1.size() + nums2.size(); 
        
        if ( tsize & 0x1 ) {
            return 1.0*nums[ ( tsize - 1 )/2 ]; 
            
        } else {
            return (1.0 * nums[ tsize/2 ] + 1.0 * nums[ tsize/2 - 1 ])/2.0; 
        }
        
    }
};

int main(void) 
{
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 6, 7, 8 , 9 };
    
    vector<int> nums1( a, a + sizeof(a)/sizeof(int));
    vector<int> nums2( b, b + sizeof(b)/sizeof(int)); 
    Solution sol;
    cout << sol.findMedianSortedArrays( nums1, nums2 ) << endl; 
    return 0; 
}