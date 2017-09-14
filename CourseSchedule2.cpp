#include <vector>
#include <utility>

using namespace std;

/*
  #   #
    #
    #
*/


class Solution {
  private:
    vector<int>   topSorted;
    vector<bool>  nodeVisited;
    vector<bool>  nodeProced;
    bool isCycle; 
    
    void dfsTopoSort(int vIdx, vector< pair<int,int> >& edges) {
        nodeVisited.at(vIdx) = true; 
        for (int e = 0; e < edges.size(); ++e) {
          if ( edges.at(e).first == vIdx ) {
            int edge_end = edges.at(e).second;
            if (!nodeVisited.at(edge_end)) {
              dfsTopoSort(edge_end, edges);
            } else if ( nodeVisited.at(edge_end) && !nodeProced.at(edge_end) ) {
              // visited, but not processed yet. then 
              // back edges. cycle detected. 
              isCycle = true; 
              break; 
            }
          } // end of processing outgoing edge
        }
        nodeProced.at(vIdx) = true; 
        topSorted.push_back(vIdx); // topologic sort is based on processed order      
    }
    
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      topSorted.resize(0);
      nodeVisited.resize(numCourses);
      nodeProced.resize(numCourses);
      
      for (int i = 0; i < numCourses; ++i) {
        nodeVisited.at(i) = false;
        nodeProced.at(i) = false; 
      }
      
      for (int i = 0; i < numCourses; ++i) {
        if ( !nodeVisited.at(i) ) {
          dfsTopoSort(i, prerequisites); 
        }
      }
      
      if (isCycle) topSorted.resize(0);
        
      return topSorted; 
    }
};
int main(void)
{
  Solution sol;
  return 0;
}