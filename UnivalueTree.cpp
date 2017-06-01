/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,

              5
             / \
            1   5
           / \   \
          5   5   5

 

return 4.
*/
// my thought

// the below is not verified. 
bool cntUniValueSubTree( TreeNode* root, int& cnt){
  if (root == NULL) return true;
  
  bool left = cntUniValueSubTree( root->left, cnt );
  if (left && root->left != NULL) left = left && (root->val == root->left->val);

  bool right = cntUniValueSubTree( root->right, cnt );
  if (right && root->right != NULL) right = right && (root->val == root->right->val);
  
  if (left && right) { cnt++; return true;}
  else return false; 
  
}