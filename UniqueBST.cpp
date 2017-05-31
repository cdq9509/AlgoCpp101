/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's. 
*/
class Solution {
public:
#if 0 
    int numTrees(int n) {
      if (n == 0 || n == 1) return 1;
      if (n == 2 ) return 2; 
      
      int cnt = 0; 
      for (int i = 1; i <= n; ++i) {
        int left = numTrees( i - 1 );
        int right = numTrees( n - i - 1 );
        cnt += (left * right );
      }
      return cnt;   
    }
#endif

public:
    int numTrees(int n) {
      if (n == 0) return 1; 
      vector<int>  dp(n+1); 
      dp.at(0) = 1;
      
      for (int i = 1; i <= n; ++i) {
        int cnt = 0; 
        for ( int k = 1; k <= i; ++k) {
          int left = dp.at( k - 1 );
          int right = dp.at( i - k );
          cnt += (left * right );
        }
        dp.at(i) = cnt;         
      }
      return dp.at(n);   
    }   

};