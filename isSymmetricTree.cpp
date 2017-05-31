/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
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
 
// Thought1: do in order traversal, then compare if the array is symmetric

#if 0 
// Recursive 
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
      if (p == NULL && q == NULL) return true;
      if (p == NULL || q == NULL) return false; 
      
      if (p->val == q->val) {
        return (helper(p->left, q->right) && helper(p->right,q->left));
      } else {
        return false;
      }
    }
    bool isSymmetric(TreeNode* root) {
      if (root == NULL) return true;
      return helper(root->left, root->right);        
    }
};
#endif

// iterative version
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
      stack< pair<TreeNode*,TreeNode*> > s;
      s.push(make_pair(p,q));
      while (!s.empty()) {
        pair<TreeNode*,TreeNode*> elem = s.top();
        s.pop();
        
        if (elem.first == NULL && elem.second== NULL) continue;
        if (elem.first == NULL || elem.second== NULL) return false;
        if (elem.first->val != elem.second->val) return false;
        
        s.push(make_pair(elem.first->left, elem.second->right));
        s.push(make_pair(elem.first->right, elem.second->left));       
        
      }
      return true; 
    }
    bool isSymmetric(TreeNode* root) {
      if (root == NULL) return true;
      return helper(root->left, root->right);        
    }
};