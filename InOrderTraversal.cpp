/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
#if 0 // recursive version is trivial
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      
      if ( root == NULL ) return res;
      if ( root->left != NULL ) {
        vector<int> tmp = inorderTraversal( root->left );
        res.insert( res.end, tmp.begin(), tmp.end() );
      }
      res.push_back( root->val ); 
      if ( root->right != NULL ) {
        vector<int> tmp = inorderTraversal( root->right );
        res.insert( res.end, tmp.begin(), tmp.end() );
      }      
        
    }
#endif 
    enum {
      ROOT,
      LEAF
    } nodeType;
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      
      if (root == NULL) return res; 
      
      stack<TreeNode*> s;
      
      s.push( root->right );
      s.push( root );
      s.push( root->left );
      
      TreeNode * elem;
      while ( !s.empty() ) {
        elem = s.top();
        s.pop();
        
        
        
      }
      
      if ( root == NULL ) return res;
      if ( root->left != NULL ) {
        vector<int> tmp = inorderTraversal( root->left );
        res.insert( res.end, tmp.begin(), tmp.end() );
      }
      res.push_back( root->val ); 
      if ( root->right != NULL ) {
        vector<int> tmp = inorderTraversal( root->right );
        res.insert( res.end, tmp.begin(), tmp.end() );
      }              
    }
    
};