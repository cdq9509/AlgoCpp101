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
    
    int maxDepth(TreeNode* root) {
      if (root == NULL) return 0;
      
      int h = 1;
      int hl = maxDepth(root->left);
      int hr = maxDepth(root->right);
      
      return h + max(hl, hr ); 
        
    }
};