/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 

*/
// I think this is straightforward, recursive on right and push the value


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#if 0
// I thought it is preorder, but it should be consider level order and get the most right side
// so below it is wrong due to
/*
Input:[1,2]
Output:[1]
Expected:[1,2]
*/
class Solution {
public:
    void dfs(TreeNode* root, vector<int> & res){
      res.push_back(root->val);
      if (root->right == NULL && root->left == NULL) {return;}      
      if (root->right != NULL) { dfs(root->right, res); return;}      
    }
    vector<int> rightSideView(TreeNode* root) {
      vector<int> res;
      if (root != NULL) dfs(root, res);
      return res;   
    }
};
#endif
