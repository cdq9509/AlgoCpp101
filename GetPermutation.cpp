class Solution {
public:
    void getRemainderQuotien( int k, int n , int& r, int & q)
    {
      int rem, quot; 
      while ( (quot = k/n) != 0 && n > 0 ) {
        k = k/n;         
        --n;
      }
      rem = k/n; 
      
    }
    string getPermutation(int n, int k) {
    }
};