/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5. 
*/

// 1. sort is easies, but use it to practice heap
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:

    // siftDown is log(i)/height operation
    void siftDownMinHeap( vector<int> &nums, int i, int n) {
      
      if ( i >= n) return; 
      
      int minIdx = i; 
      for (int j = 0; j <=1; ++j) {
        int idx = 2*i + 1 + j;
        if (idx >= n) break;
        if ( nums.at(minIdx) > nums.at(idx) ) { minIdx = idx; }
      }
      if ( minIdx != i ) {
        swap( nums.at(i), nums.at(minIdx) ); 
        siftDownMinHeap(nums, minIdx,n);
      }
    }

    void siftDownMaxHeap( vector<int> &nums, int i, int n) {
      if ( i >= n) return; 
      
      int maxIdx = i; 
      for (int j = 0; j <=1; ++j) {
        int idx = 2*i + 1 + j;
        if (idx >= n) break;
        if ( nums.at(maxIdx) < nums.at(idx) ) { maxIdx = idx; }
      }
      if ( maxIdx != i ) {
        swap( nums.at(i), nums.at(maxIdx) ); 
        siftDownMaxHeap(nums, maxIdx,n);
      }
    }
    
    // construct heap is only o(n)
    void constructMaxHeap( vector<int> &nums ) {
      int n = nums.size();
      
      // n/2 is floor operation. 
      // (i-1)/2 gives the parent. 
      // 2*i+1 the left child. It is a binary tree. so we know the right child is 2*i+2. 
      // now remember, parent < min(left, right), but no guarantee beteween left and right
      for (int i = (n - 1)/2; i >= 0; --i) {
        siftDownMaxHeap(nums, i,n);
      }
    }
    
    void siftUpMaxHeap( vector<int>& nums, int n, int i ) {
      // acttually n (size) is not needed for siftUp
      if (i == 0) return;
      int p = (i-1)/2;
      if ( nums.at(p) < nums.at(i) ) {
        swap(nums.at(p), nums.at(i));
        siftUpMaxHeap(nums, n, p );
      }      
    }
    
    void HeapSort(vector<int> &nums){
      
      constructMaxHeap(nums);
      
      // Max is first elem, swap with the last elem
      for (int i = nums.size() - 1; i > 0; --i) {
        swap( nums.at(0), nums.at(i) );
        siftDownMaxHeap(nums, 0, i ); 
      }      
    }
    
    int findKthLargest(vector<int>& nums, int k) {
       HeapSort(nums);
       return nums.at(nums.size() - k); 
    }
};

int main(void) {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);
  
  
  return 0;
}