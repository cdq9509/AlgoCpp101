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
    vector<TreeNode*> helper( int start, int end ) {
      vector<TreeNode*> res; 
      
      if ( start > end ) { res.push_back(NULL); return res; }
      
      for (int i = start; i <= end; ++i ) {
        vector<TreeNode*> leftRoots = helper(start, i-1 );
        vector<TreeNode*> rightRoots = helper(i+1, end);
        for (int j = 0; j < leftRoots.size(); ++j) {
          for (int k = 0; k < rightRoots.size(); ++k) {
            TreeNode * root = new TreeNode(i);
            root->left = leftRoots.at(j);
            root->right = rightRoots.at(k);
            res.push_back(root); 
          }
        }
      }
      return res; 
    }
    
    vector<TreeNode*> generateTrees(int n) {
      vector<TreeNode*> res;
      if ( n == 0 ) return res;
      res = helper(1, n );  
      return res;         
    }
};