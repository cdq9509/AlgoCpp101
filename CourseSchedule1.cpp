#include <vector>
#include <iostream>

using namespace std;

class Solution {
  private:
    vector<int> nodeVisited;
    vector<int> nodeProced;
    bool isCycle;
    
    void dfs( int vIdx, vector< pair<int,int> > & edges ) {
    
      nodeVisited.at(vIdx) = true; 
      
      vector< pair<int,int> >::iterator edge;
      for (edge = edges.begin(); edge != edges.end(); ++edge) {
        if (edge->first == vIdx) {
          // vIdx -> dst
          int dst = edge->second; 
          if (!nodeVisited.at(dst)) {
            dfs(dst,edges);
          } else if (nodeVisited.at(dst) && !nodeProced.at(dst)) {
            isCycle = true; 
            break;
          }
        }
      }
      nodeProced.at(vIdx) = true;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      nodeVisited.resize(numCourses, false);
      nodeProced.resize(numCourses, false);
      isCycle = false; 
      
        for (int i = 0; i < numCourses; ++i) {
          if (!nodeVisited.at(i)) {
            dfs(i, prerequisites);
          }
          if (isCycle) break;
        }
        return !isCycle; 
    }
};

int main(void)
{
  Solution sol;
  return 0;
}

