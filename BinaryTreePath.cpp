/* Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
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

// this is recursion and how to convert int to string. I use snprintf. a safe function
// use sscanf for string to int
// need to include <cstdio> 
 
class Solution {
public:
#define MAX_SLEN 256
    vector<string> binaryTreePaths(TreeNode* root) {
      char s[MAX_SLEN];
      vector<string> res;
      if (root == NULL) return res;
      
      if (root->left == NULL && root->right == NULL) {
        int cx = snprintf( s, MAX_SLEN, "%d", root->val);
          if (cx > 0 && cx < MAX_SLEN) {
            res.push_back( string(s) ); 
          } 
          return res;
      }
      
      if (root->left != NULL) {
        vector<string> left = binaryTreePaths(root->left);
        for (int i = 0; i < left.size(); ++i) {
          int cx = snprintf( s, MAX_SLEN, "%d->%s", root->val, left.at(i).c_str());
          if (cx > 0 && cx < MAX_SLEN) {
            res.push_back( string(s) ); 
          } else {
            // throw exceptions
          }
        }
      } // all left
      
      if (root->right != NULL) {
        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < right.size(); ++i) {
          int cx = snprintf( s, MAX_SLEN, "%d->%s", root->val, right.at(i).c_str());
          if (cx > 0 && cx < MAX_SLEN) {
            res.push_back( string(s) ); 
          } else {
            // throw exceptions
          }
        }
      } // all right
      return res; 
    }
};