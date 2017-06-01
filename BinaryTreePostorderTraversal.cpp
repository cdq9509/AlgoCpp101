/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // The problem ask for non-recursive solution
 
// Let me first find recursive 
#if 0 
class Solution {
public:
    void helper(TreeNode* root, vector<int> &res) {
      if (root->left == NULL && root->right == NULL) {
        res.push_back(root->val);
        return; 
      }
      if (root->left != NULL) helper(root->left, res);
      if (root->right != NULL) helper(root->right, res);
      res.push_back(root->val);
      return; 
    }
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      helper(root, res);        
    }
};
#endif 

class Solution {
public:
    typedef enum {
      INIT, 
      LEFT_VISITED,
      RIGHT_VISITED,
      DONE
    } State;
    typedef struct {
      TreeNode * root;
      State      state; 
    } SEntry; 
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res; 
      stack<SEntry> s;
      
      {SEntry t; t.root = root; t.state = INIT;
      s.push(t);}
      
      while (!s.empty()){
        SEntry elem = s.top();
        s.pop();
        
        if (elem.root == NULL) continue; 
          
        if (elem.root->left == NULL && elem.root->right == NULL) 
        { res.push_back(elem.root->val);continue;}
        
        switch( elem.state) {
          case INIT:
          {SEntry t; t.root = elem.root->left; t.state = INIT;
            elem.state = LEFT_VISITED;
            s.push(elem);
            s.push(t);
          break; }
          case LEFT_VISITED:
          {SEntry t; t.root =elem.root->right; t.state = INIT;
            elem.state = RIGHT_VISITED;
            s.push(elem);
            s.push(t);
          break;}
          case RIGHT_VISITED:
          {res.push_back(elem.root->val);
          break;}
        }
      }
      return res;
    }
};