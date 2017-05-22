#include <iostream>

#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
        
        for(unsigned int i = 0; i < matrix.size(); ++i ){
          for(unsigned int j = 0; j < matrix.at(i).size(); ++j) {
            minHeap.push( matrix.at(i).at(j) ); 
          }
        }
        int val; 
        while ( k > 0 ) {
          val = minHeap.top();
          minHeap.pop();
          --k;
        }
        return val;
    }
};
int main(void) 
{
  Solution sol;
  vector< vector<int> > mat;
  /*
  vector<int> LL;
  LL.push_back(1);
  LL.push_back(3);
  LL.push_back(5);
  mat.push_back(LL);
  
  LL.resize(0);
  LL.push_back(6);
  LL.push_back(7);
  LL.push_back(12);
  mat.push_back(LL);

  LL.resize(0);
  LL.push_back(11);
  LL.push_back(14);
  LL.push_back(14);
  mat.push_back(LL);
  */

  vector<int> LL;
  LL.push_back(0);
  LL.push_back(0);
  LL.push_back(0);
  mat.push_back(LL);
  
  LL.resize(0);
  LL.push_back(2);
  LL.push_back(7);
  LL.push_back(9);
  mat.push_back(LL);

  LL.resize(0);
  LL.push_back(7);
  LL.push_back(8);
  LL.push_back(11);
  mat.push_back(LL);

  
  int val = sol.kthSmallest(mat,7);
  cout << val << endl;
  
  
  
  return 0;
}