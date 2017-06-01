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





/* Adjency List: each node x has a list that represents edge connecting it with other nodes (y) */
#if 0
// basic 
#define MAXV 100
typedef struct {
  int y; // src -> dst. src (x) is assumed. This y is dst;
  struct outEdgeNode * next; // next edge 
} outEdgeNode; 
typedef struct {
  outEdgeNode * verticesList[MAXV+1];
  int degree[MAXV+1];
  int nvertices; 
  int nedges;
} graph;
#endif 

#if 0 
This captures the essence with another info
typedef struct {
  int y;
  int w; // weight
} outEdgeNode;
typedef struct {
  vector< list<outEdgeNode> > vertices; // each entry of vertices is a adjaceny list
} graph; 
#endif 

#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

// my unidirected graph
class graph {
#define INVALID_PARENT  (-1)
typedef enum {
  WHITE, // not discovered (entered) yet
  GRAY, // discovered, but not processed yet
BLACK, // processed
} color_e; 
  private: 
    vector< list<int> > vAdjList;// vertice's adj list
    
    vector<int>  parent; // parent.at(j) --> parent of node j

    vector<bool> discovered; //discovered.at(j) --> node j is discovered
    vector<bool> processed; // processed; A node is first discovered (entered) then processed (exit). 
    ///////////////
    color_e      color; // This is == discovered + processed. We only need one set. Here is only for illustration
                        // A lot of standard text book use color, but Skienna use discovered & processed
    
    
    bool isCircle; 
  public:
    graph(int n) { 
      vAdjList.resize(n);
      discovered.resize(n);
      processed.resize(n);
      parent.resize(n); 
      for (int i = 0; i < n; ++i) {
        processed.at(i) = discovered.at(i) = false;        
        parent.at(i) = INVALID_PARENT;
      }
      isCircle = false;       
    }
    
    void insertEdge(int x, int y) {
      vAdjList.at(x).push_back(y);
      vAdjList.at(y).push_back(x);
    }
    void bfs(int x) {
      queue<int> q;
      
      discovered.at(x) = true; 
      q.push(x);
      
      while (!q.empty()) {
        int e = q.front();
        q.pop();
        
        list<int>::iterator adjIt;
        for (adjIt = vAdjList.at(e).begin(); adjIt = vAdjList.at(e).end(); ++adjIt) {
          int y = *adjIt; 
          if (!discovered.at(y)) {
            parent.at(y) = e;
            discovered.at(y) = true; 
            q.push(y);
          } else if ( discovered.at(y) && parent.at(y) != e )
          // now if discovered.at(y) is discovered, is it indication of a cycle?
          // for directed graph, it is not: as below
          //    1 --->2 ---> 3 -->4
          //      (1)-->5 --->6 ->(4)
          // also for undirected graph, the edge will be visited twice just like DFS
          // EG: (above graph)
          //    we push 1
          //    pop 1, push 2, 5
          //    pop 2, push (1), 3. Now 1 is processed already. so ignore
          //    pop 5, push (1), 6. Now 1 is processed. so ignore
          //    pop 3, push 4.  Now 4 is discovered
          //    pop 6, push 4, but 4 is discovered??? so we check whether it has parents the same as e(src itself) 
          // seems to work??? 
          // detect a circle
        }
        processed.at(e) = true; 
        
      }
    }
    void dfs(int x) {
      
      if (isCircle) return; 
      
      discovered.at(x) = true;
      
      list<int>::iterator adjIt; 
      for (adjIt = vAdjList.at(x).begin(); adjIt != vAdjList.at(x).end(); ++adjIt) {
        int y = *adjIt;
        if (discovered.at(y) == false) {
          parent.at(y) = x;
          // process_edge(x,y)
          dfs(y);
        } else if ( !processed.at(y) && parent.at(x) != y ) {
          // y has been discovered before, but not processed, meaning that
          // this must be first time of visiting this edge (x<->y) unless
          // y is an immediate ancestor of x. 
          // This is a back edge! 
          // In undirected graph, we still need to process this edge
          // process_edge(x,y)
          // 
          // Note that in a directed graph, the whole condition is not needed: if
          // discovered.at(y) == true, we have a circle. 
          // we still processed the edge
          isCircle = true;          
        } 
#if 0        
        else if ( processed.at(y) || (!processed.at(y) && parent.at(x) == y) ){
          // One edge is traversed twice even without cycle in undirected graph.
          // one from x's adjList. The other from y's adjList.
          // This is the second time and is fine.
          // 
          // The second condition is also the second time that 
          // we visit a x->y
          //
          // so this branch we basically do not do anything. 
        }
#endif         
      } // iterate over all adjencies edges
      
      processed.at(x) = true; 
    }
    
    bool isAcyclic() { return !isCircle; }
    
    bool isConnected() {
      for (int i = 0; i < processed.size(); ++i){
        if (!processed.at(i)) return false;
      }
      return true; 
    }
}; 

class Solution {

public:
    bool validTree(int n, vector<pair<int, int> >& edges) {
      graph g(n); 
      vector<pair<int,int> >::iterator edgeIt; 
      for (edgeIt = edges.begin(); edgeIt != edges.end(); ++edgeIt) {
        g.insertEdge( edgeIt->first, edgeIt->second);
      }
      g.dfs( edges.at(0).first );
      
      return ( g.isConnected() && g.isAcyclic() ) ;
      
    }
};

int main(void){
  Solution sol;
  
  int n = 4;
  vector<pair<int,int> > edges;
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(1,2));
  edges.push_back(make_pair(2,3));
  edges.push_back(make_pair(3,0));
  cout << "expect" << false << " Get" << sol.validTree(n, edges) << endl;
  
  n = 4;
  edges.resize(0);
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(1,2));
  // edges.push_back(make_pair(2,3));
  edges.push_back(make_pair(0,3));
  cout << "expect" << true << " Get" << sol.validTree(n, edges) << endl;
  
  
}

