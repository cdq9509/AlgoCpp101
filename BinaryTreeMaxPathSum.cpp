 /*Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
     return 6
*/

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
    void helper(TreeNode* root, int &maxSumFrom, int &maxSumLCA, int &maxSumSoFar) {
      int maxSumIncludeRoot;
      
      if ( root->left == NULL && root->right == NULL ) { 
        maxSumFrom = maxSumLCA = maxSumIncludeRoot = root->val;         
        maxSumSoFar = max( maxSumSoFar, maxSumIncludeRoot );
        return;
      }
      
        int maxSumFromLeft = INT_MIN, maxSumLCALeft = INT_MIN;
        if (root->left != NULL) helper( root->left, maxSumFromLeft, maxSumLCALeft, maxSumSoFar );
        
        int maxSumFromRight = INT_MIN, maxSumLCARight = INT_MIN;
        if (root->right != NULL) helper( root->right, maxSumFromRight, maxSumLCARight, maxSumSoFar);
        
        maxSumLCA = max( maxSumFromRight, 0) + max(maxSumFromLeft, 0) + root->val; 
        maxSumFrom = max( max( maxSumFromRight, 0), max(maxSumFromLeft, 0) ) + root->val; 
        
        maxSumIncludeRoot = max(maxSumLCA, maxSumFrom);
      
      maxSumSoFar = max( maxSumSoFar, maxSumIncludeRoot );
      return; 
    }
    int maxPathSum(TreeNode* root) {
        int maxSumFrom, maxSumLCA, maxSumSoFar = INT_MIN;
        helper(root, maxSumFrom, maxSumLCA, maxSumSoFar);
        return maxSumSoFar;
    }
};