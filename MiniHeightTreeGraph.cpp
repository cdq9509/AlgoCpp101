/*
 For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]

Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf. 

*/

#include <vector>
#include <list>
#include <iostream> 
using namespace std;


#if 0 
// my thought: do a DFS, start from each node. This works (it pass 64 out of 66 tests) but exceed the time limit when n= 50001
/*

grandyang --> https://discuss.leetcode.com/topic/30572/share-some-thoughts good discussions. 
website said this is similar as 
Course Schedule II

Course Schedule

Clone Graph
*/
class Graph {
#define INVALID_PARENT -1  
  typedef enum {
    WHITE,
    GRAY,
    BLACK
  } color_e; 
  private: 
    vector<list<int> > mAdjList;
    vector<color_e>    mColor;
 
  public:
    Graph(int n) {mAdjList.resize(n); mColor.resize(n, WHITE); }
    void reinit() { int n = mAdjList.size(); mColor.resize(0); mColor.resize(n,WHITE);}
    
    bool dfs(int p, int parent, int pH, int & maxHeight) {
      // return false if cycle detected
     
      bool cyclic = false; ; 
      
      mColor.at(p) = GRAY;
      int currentHeight = pH + 1; 
      maxHeight = max(maxHeight, currentHeight);
      
      list<int>::iterator u;
      for (u = mAdjList.at(p).begin(); u != mAdjList.at(p).end(); ++u) {
        int y = *u;
        if ( mColor.at(y) == WHITE ) {
          // Tree edge
          mColor.at(y) = GRAY;
          cyclic = dfs(y, p, currentHeight, maxHeight);
          if (cyclic) return cyclic; 
        } else if ( mColor.at(y) != WHITE && parent != y ) {
          // back edge here
          cyclic = true;
          return cyclic;
        }          
      }
      return cyclic; 
    }
    
    void insertEdge( int p, int q) {
      mAdjList.at(p).push_back(q);
      mAdjList.at(q).push_back(p);
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        Graph graph(n); 
        for (int i = 0; i < edges.size(); ++i) {
          graph.insertEdge( edges.at(i).first, edges.at(i).second);
        }
        
        int minH = n + 1; 
        vector<int> res; 
        for (int i = 0; i < n; ++i) {
         
          int mh = 0; 
          graph.reinit();
          if (! graph.dfs(i, -1, -1, mh)) {
            
            if (mh < minH) { res.resize(0); res.push_back(i); minH = mh; }
            else if (mh == minH) { res.push_back(i);}            
          }
        }
        return res; 
    }
};
#endif 

int main(void){
  Solution sol;
  
  int n = 4;
  vector<pair<int,int> > edges;
  edges.push_back(make_pair(1,0));
  edges.push_back(make_pair(1,2));
  edges.push_back(make_pair(1,3));
 
  vector<int> res = sol.findMinHeightTrees(n, edges);
  
  
}


#if 0 
public class Solution {
    // assume the given graph is connected and acyclic
    int maxHeight = 0, leafNode = -1;;
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if(n==0) return res;
        if(n==1) {
        	res.add(0);
        	return res;
        }
        List<Integer>[] adj = new ArrayList[n];
        for(int i=0; i<n; i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int[] edge : edges){
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }
        
        int[] heights = new int[n];
        dfs(0, 0, adj, 1, heights);
        int start = leafNode;
        dfs(start, start, adj, 1, heights);
        
        int maxH = maxHeight;
        int midH = (maxH+1)/2 ;
        
	int node1;
	for (node1 = 0; node1 < n; node1++) {
		if (heights[node1] == midH) { // && heights2[i] == midH+1
    		res.add(node1); break;
		}
	}
	if (maxH % 2 == 0) { // even
		int[] heights2 = new int[n];
		dfs(leafNode, leafNode, adj, 1, heights2);
		for(int node : adj[node1]){
			if(heights[node]==midH+1 && heights2[node] == midH){
				res.add(node); break;
			}
		}
	}
        return res;
    }
    private void dfs(int node, int parent, List<Integer>[] adj, int height, int[] heights){
    	if(height > maxHeight) maxHeight = height;
    	heights[node] = height;
    	boolean isLeaf = true;
        for(int neighbor : adj[node]){
            if(neighbor != parent){
            	isLeaf = false;
            	dfs(neighbor, node, adj, height+1, heights);
            }
        }
        if(isLeaf && height == maxHeight)
        	leafNode = node;
    }
}
#endif 