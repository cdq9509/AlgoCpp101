/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/


 //Definition for a binary tree node.
 
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
      vector< vector<int> >  res; 
      if (root == NULL) return res;
      
      queue<TreeNode*> q;
      q.push(root);
      bool isZig = true; 
      while (!q.empty()) {
        int size = q.size();
        vector<int> tmp;
        for(int i = 0; i < size; ++i) {
          TreeNode* elem;
          elem = q.front();
          q.pop(); 
          if (elem != NULL) tmp.push_back(elem->val);
          if (elem->left != NULL) q.push(elem->left);
          if (elem->right != NULL) q.push(elem->right);             
        }
        if (!isZig) {
          reverse( tmp.begin(), tmp.end() ); 
        }
        res.push_back( tmp ); 
        isZig = !isZig;
      }
      return res; 
        
    }
};

int main(void)
{
  Solution sol;
  return 0;
}