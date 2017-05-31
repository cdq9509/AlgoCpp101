/* Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 

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
 
#include <vector>
#include <cstddef>

using namespace std;

      struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
#if 0 // This is recursive and therefore o(n) space actually  
class Solution {
  private:
    TreeNode * first;
    TreeNode * second; 
    TreeNode * prev; 
public:

    void visit(TreeNode* root) {
      if ( prev != NULL && root->val < prev->val ) {
        if (!first) first = prev; 
        second = root; 
      }
      prev = root; 
    }
    void inOrderTraversal(TreeNode* root)
    {
      if (root == NULL) return;
      
      inOrderTraversal(root->left);
      
      visit( root );
      
      inOrderTraversal(root->right);
      
      return; 
      
    }
    void recoverTree(TreeNode* root) {
      first = second = prev = NULL; 
      
      inOrderTraversal( root );

      if ( first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp; 
      }
      
    }
};
#endif

// Surprisingly: morris inorder traversal is not really efficient in real running compared with the above. 
class Solution {
  private:
    TreeNode * first;
    TreeNode * second; 
    TreeNode * prev2; 
public:

    void visit(TreeNode* root) {
      if ( prev2 != NULL && root->val < prev2->val ) {
        if (!first) first = prev2; 
        second = root; 
      }
      prev2 = root; 
    }
    void inOrderTraversal(TreeNode* root)
    {
      TreeNode * current = root;
      TreeNode * prev; // Predecessor
      
      while ( current != NULL ) {
        if ( current->left == NULL ) {
          // leaf node
          visit(current);
          current = current->right;
        } else {
          // find the right most child of left subtree
          prev = current->left;
          while ( prev->right != NULL && prev->right != current ){
            prev = prev->right; 
          }
          if (prev->right == NULL) {
            // we are at right most child of left subtree
            prev->right = current; 
            current = current->left; 
          } else {
            // prev->right == current. need to go to right subtree
            prev->right = NULL; // restore tree
            visit(current); 
            current = current->right; 
          }
        }
      }
      
      return; 
      
    }
    void recoverTree(TreeNode* root) {
      first = second = prev2 = NULL; 
      
      inOrderTraversal( root );

      if ( first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp; 
      }
      
    }
};


int main(void) 
{
  Solution sol; 
}