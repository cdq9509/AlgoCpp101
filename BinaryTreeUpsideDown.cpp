/*
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, 
flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:

Given a binary tree {1,2,3,4,5},

    1

   / \

  2   3

 / \

4   5

return the root of the binary tree [4,5,2,#,#,3,1].

   4

  / \

 5   2

    / \

   3   1
*/

// my thought: is this related with RB tree rotation?? or somewhat related?

// recursive
class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
      if (root->left == NULL || root == NULL) return root;
      
      // root->left will also be the bottom node that we need to connect
      TreeNode * left = root->left;
      TreeNode * right = root->right
      TreeNode * newRoot = upsideDownBinaryTree( left ); 
      
      left->right = root;
      left->left = right;
      root->left = root->right = NULL: 
      
      return newRoot; 
      
    }
};

