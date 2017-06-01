/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.


Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
/*
Hint:

    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
    According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
    */
    
// my thought:
// 1. must be connected (exists a node that can reach all nodes)
// 2. wait: we don't care the direction. ->unidirected. --> graph: can I reach all node starting from one arbitrary node. --> is graph connected?
// 3. shall not have simple cycle
// 
// 
// Related with connected component?? 
class Solution {
#define INVALID_PARENT  (-1)
public:
    vector<bool> discovered; //discovered.at(j) --> node j is discovered
    vector<int>  parent; // parent.at(j) --> parent of node j
    
    vector<int> adj( vector<pair<int, int> >& edges, int v ) {
      //int v = edge.first;
      vector<int> adjList;
      //adjList.push_back(edge.second);
      for (int i = 0; i < edges.size(); ++i) {
        //if ( edges.at(i) == edge ) {continue;}
        if (edges.at(i).first == v) adjList.push_back(edges.at(i).second;
        if (edges.at(i).second == v) adjList.push_back(edges.at(i).first;
      }
      return adjList; 
    }
    void dfs( vector<pair<int, int> > & edges, int v ) {
      int v = edge.first;
      discovered.at(v) = true; 
      
      vector<int> adjList = adj(edges, edge);
      vector<int>::iterator u; 
      for(u = adjList.begin(); u!= adjList.end();++u) {
          dfs(edges, u);
      }
    }
    bool validTree(int n, vector<pair<int, int> >& edges) {
      discovered.resize(n);
      parent.resize(n); 
      for (int i = 0; i < n; ++i) {
        discovered.at(i) = false;
        parent.at(j) = INVALID_PARENT;
      }
      
      pair<int,int> edge = edges.front();
      
      
    }
};

