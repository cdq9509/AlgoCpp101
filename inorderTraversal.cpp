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
    typedef enum {
      ROOT,
      LEAF
    } nodeType;
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;      
      if (root == NULL) return res; 
      
      stack< pair<TreeNode*, nodeType> > s;
      
      s.push( make_pair( root, LEAF ) );
      pair<TreeNode*, nodeType> e;      
      while ( !s.empty() ) {
        e = s.top();
        s.pop();
        if (e.second == ROOT) { res.push_back( e.first->val ); continue; }
        TreeNode * t = e.first;
        if (t->right != NULL) s.push( make_pair( t->right, LEAF ) );
        s.push( make_pair( t, ROOT ) );
        if (t->left != NULL) s.push( make_pair( t->left, LEAF ) );
      }
     return res;    
    }
};