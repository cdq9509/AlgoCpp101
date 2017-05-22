#include <iostream>

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    class Cell {
      public:
        unsigned int x;
        unsigned int y;
        int val;
        Cell( unsigned int inx, unsigned int iny, int inval ) {
          x = inx;y=iny; val=inval;
        }
        Cell() {}
    }; 
    class Greater {
      public:
        bool operator()( const Cell &c0, const Cell &c1 ) {
          return ( c0.val > c1.val ); 
        }
    };
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        priority_queue<Cell, std::vector<Cell>, Greater> minHeap;
        unsigned int n = matrix.size();
                
        Cell elem(0,0,matrix.at(0).at(0));
        vector<Cell> lastSameValSet; 
        
                
        int cnt = 0;
        minHeap.push( elem );
        while (cnt < k) {
          elem = minHeap.top();
          //cout << "###" << elem.val << endl;
          minHeap.pop();
          
          // Detect if this is a repeat of previous elem
          bool isRepeat = false;
          if ( lastSameValSet.size() != 0 ) { 
            for (unsigned int j = 0; j < lastSameValSet.size(); ++j) {
              if ( lastSameValSet.at(j).val != elem.val ) { lastSameValSet.resize(0); break;}
              if (lastSameValSet.at(j).x == elem.x && lastSameValSet.at(j).y == elem.y ) {isRepeat = true; break; }
            }
          } 
          if (isRepeat) continue; 
          
          // how to avoid repeat
          if (elem.x+1 < n) { minHeap.push( Cell( elem.x+1, elem.y, matrix.at( elem.x + 1 ).at(elem.y) )); }
          if (elem.y+1 < n) { minHeap.push( Cell( elem.x, elem.y+1, matrix.at( elem.x ).at( elem.y + 1 )) ); }
          lastSameValSet.push_back( elem ); 
          ++cnt;
           
        }
      
        return elem.val; 
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