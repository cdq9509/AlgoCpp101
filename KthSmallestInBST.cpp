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
    TreeNode* in_order_traversal( TreeNode* root, int k, int & cnt) {
      
        // I could be access null; so do NOT use root->left == NULL && root->right == NULL
        if (root == NULL) { return root;}
        
        // visit left
        TreeNode* val = in_order_traversal( root->left, k, cnt);
        if ( val != NULL && cnt >= k) return val;
        
        // visit root
        cnt++;
        if ( cnt >= k) return root; 
        
        // visit right
        val = in_order_traversal( root->right, k, cnt);
        if ( val != NULL && cnt >= k ) return val; 
        
        return NULL; 
      
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        TreeNode* val = in_order_traversal( root, k, cnt );
        return val->val;
    }
};

