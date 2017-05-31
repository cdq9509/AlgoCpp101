
/* 1 3 6 5 4 2 */

class Solution {
public:
    void swap( vector<int>& nums, int i, int j ) {
      int tmp = nums.at(i);
      nums.at(i) = nums.at(j);
      nums.at(j) = tmp;
    }
    void nextPermutation(vector<int>& nums) {
      
      // Find descending suffix starting at P
      int p = nums.size() - 1;
      while ( p > 0 && nums.at(p-1) >= nums.at(p) ) {
        --p;
      }
      
      // Last permutation (at max) already
      if ( p <= 0 ) { sort(nums.begin(), nums.end()); return;} 
           
      // P-1 is the pivot to be swapped
      int val = nums.at(p-1); 
      int i;
      for (i = nums.size() - 1; i >= p; --i ) {
        if ( nums.at(i) > val ) break;       
      }
      
      // swap 
      swap( nums, p-1, i );
      
      // reverse order from p to end
      int l = p, r = nums.size() - 1; 
      
      while ( l < r ) {
        swap( nums, l, r ); 
        ++l;--r;
      }
    }
};