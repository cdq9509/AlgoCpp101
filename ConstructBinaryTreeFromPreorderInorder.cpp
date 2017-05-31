/*Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
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
#include <iostream>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode * helper( vector<int> & preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
      
      // cout << ps << "," << pe << "," << is << "," << ie << endl; 
      
      if (ps > pe || ps < 0 || pe >= preorder.size()) return NULL;
      
      int pR = ps;       
      int rootVal = preorder.at(pR);      
      TreeNode * root = new TreeNode( rootVal );
      
      if (ps >= pe) return root; 
      
      int iRoot; 
      for (int i = is; i <= ie; ++i) {
        if (inorder.at(i) == rootVal) {iRoot = i; break;}
      }
            
      TreeNode* left = helper( preorder, ps + 1, ps + (iRoot - is), inorder, is, iRoot - 1 );
      TreeNode* right = helper( preorder, pe - (ie - iRoot - 1), pe, inorder, iRoot+1, ie);
      
      root->left = left;
      root->right = right;
      return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.size() <= 0) return NULL;
      
      TreeNode * root = helper( preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() -1 );
      return root;
      
        
    }
};

int main(void)
{
  int pa[] = { 1, 2};
  int ia[] = { 2, 1};
  
  
  vector<int> preorder( pa, pa + sizeof(pa)/sizeof(pa[0]));
  vector<int> inorder( ia, ia + sizeof(ia)/sizeof(ia[0]));
  
  Solution sol;
  sol.buildTree( preorder, inorder );
  
  return 0; 
}