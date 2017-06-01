/*LCA of Binary Tree, but not BST */
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode*q){
      if (root == p || root == q) return root; 
      if (root->right == NULL && root->left == NULL) return NULL; 
      
      TreeNode * left = NULL;
      if (root->left != NULL) left = helper(root->left,p,q);
      TreeNode * right = NULL;
      if (root->right != NULL) right = helper(root->right,p,q);
      
      if ((left == p && right == q) || (left == q && right == p)) {
        return root; 
      } else if (left == NULL && right != NULL) {return right;}
      else if (right == NULL && left != NULL) { return left;}
      else { return NULL;}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return helper(root,p,q);
    }
};

// The above can be simplifed as
#if 0
// this is from grandyang
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
       if (left && right) return root;
       return left ? left : right;
    }
};
#endif
