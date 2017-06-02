/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
      map< UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
public:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
      if (node == NULL) return NULL;
      
      UndirectedGraphNode* newRoot = new UndirectedGraphNode( node->label );
      nodeMap[node] = newRoot;
      
      for (int i = 0; i < node->neighbors.size(); ++i) {
        UndirectedGraphNode* y = node->neighbors.at(i); 
        if (y != NULL && nodeMap.find(y) == nodeMap.end()) {
          // node Y just get discovered
          dfs( y ); 
        } 
        // we don't care whether it is a back edge. WE are cloning graph!!!!
        if (y!= NULL) newRoot->neighbors.push_back( nodeMap[y] ); 
        else newRoot->neighbors.push_back(NULL); 
      }
      return newRoot; 
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      return dfs(node);        
    }
};