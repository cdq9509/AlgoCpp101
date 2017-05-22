#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // permutation v.s combinations
    // use recursive
    
    // utility fcn: to implement python slice  and concatenation
    vector<int> slice(vector<int> nums, unsigned int n) 
    {
        vector<int> res;
        res.resize( nums.size() - 1 ) ;
        
        for ( unsigned int i = 0; i < n; i++ ) {
            res[i] = nums[i]; 
        }
        for ( unsigned int j = n + 1; j < nums.size(); j++ ) {
            res[j-1] = nums[j]; 
        }
        return res; 
    }
    
    vector< vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res; 
        if ( nums.size() == 0 ) return res; 
        if ( nums.size() == 1 ) {
            res.push_back( nums ); 
        }
        
        for (unsigned int i = 0; i < nums.size(); i++ ) {
            int n = nums[i]; 
            vector<int> s = slice( nums, i ) ; 
            vector<vector<int> > r = permute( s ); 
            for ( unsigned int j = 0; j < r.size(); j++ ) {
                vector<int> t = r[j]; 
                t.insert( t.begin(), n ); 
                res.push_back( t ); 
            }        
        }
        return res; 
    }
};


int main(void)
{
    Solution sol; 
    
    int a[] = { 1, 2, 3, 4 };
    vector<int> as( a, a + sizeof(a)/sizeof(int) );
    vector<vector<int> > ar = sol.permute( as ); 
    for (unsigned int i = 0; i < ar.size(); i++ ) {
        for( unsigned int j = 0; j < ar[i].size(); j++ ) {
            cout << ar[i].at(j) << ","; 
        }
        cout << endl; 
    }
    
    
    return 0;
}