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
    TreeNode* flattenHelper(TreeNode* root) {
      if (root == NULL) return NULL; 
      if (root->right == NULL && root->left == NULL) return root;
       
      TreeNode * right = root->right;
      TreeNode * tail = root; 
      if (root->left != NULL) {
        tail = flattenHelper(root->left);
        root->right = root->left; 
        root->left = NULL;
      }
      
      TreeNode * tail2 = tail;
      
      if (right != NULL) {
        tail2 = flattenHelper(right); 
      
        tail->right = right; 
        tail->left = NULL;
      }
      
      return tail2; 
    }
    
    void flatten(TreeNode* root) {
        
      if (root == NULL) return;
      
      flattenHelper(root);
      
    }
};