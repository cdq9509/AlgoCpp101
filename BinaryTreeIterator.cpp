/*Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // inorder non-recursive traversal did not need a state.
 // my current inordertraversal.cpp is overwriteen and also use a state. that is not needed. 
 
class BSTIterator {
private: 
  stack< TreeNode *> mStack; 
  
public:
    BSTIterator(TreeNode *root) {
      while (root != NULL) {
        mStack.push(root);
        root = root->left; }        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mStack.empty(); 
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * root = mStack.top();
        mStack.pop();
        
        // if (root->left == NULL && root->right == NULL) return root->val; 
        if (root->right != NULL) {
          TreeNode * t = root->right;
          while (t!= NULL) {mStack.push(t); t = t->left;}
        }
        return root->val; 
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */