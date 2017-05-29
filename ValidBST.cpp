/**

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

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
    bool helperValidBST(TreeNode *root, int& min, int &max) {
      if (root == NULL) return true;
      if (root->left == NULL && root->right == NULL) {
        min = max = root->val;
        return true;
      }
      
      int leftMin, leftMax, rightMin, rightMax;
      bool leftB, rightB;
      if (root->left != NULL  & root->right != NULL) {
        leftB = helperValidBST(root->left, leftMin, leftMax);
        rightB = helperValidBST(root->right, rightMin, rightMax);
        if (!leftB || !rightB || root->val <= leftMax || root->val >= rightMin )  return false;
        else { min = leftMin; max = rightMax; return true; }
      } else if (root->left == NULL) {
        rightB = helperValidBST(root->right, rightMin, rightMax);
        if ( !rightB || root->val >= rightMin ) return false;
        else { min = root->val; max = rightMax; return true;}
      } else {
        leftB = helperValidBST(root->left, leftMin, leftMax);
        if (!leftB || root->val <= leftMax )  return false;  
        else { min = leftMin; max = root->val; return true; }
      }      
    }
    
    bool isValidBST(TreeNode* root) {
      int min, max;
      return helperValidBST( root, min, max ); 
        
    }
};