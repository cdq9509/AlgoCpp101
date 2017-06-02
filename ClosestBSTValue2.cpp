/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

    Given target value is a floating point.
    You may assume k is always valid, that is: k ≤ total nodes.
    You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

 

Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

*/

// do in order traversal, we keep a max heap of K size, (heap's element is ordered by their difference to input.
// we can use the BST tree property to avoid using heap: 
// in order traversal produced from left to right (large to small), now take an subarray, we get another in order 
// traversal. 
// so if next is closer compared to the first one in that "heap subarray", we move the sliding window to right
// by removing the first one out. !!! 
// This is beatiful!!

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k, res);
        return res;
    }
    void inorder(TreeNode *root, double target, int k, vector<int> &res) {
        if (!root) return;
        inorder(root->left, target, k, res);
        if (res.size() < k) res.push_back(root->val);
        else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else return;
        inorder(root->right, target, k, res);
    }
};


/*
Hint:

1. Consider implement these two helper functions:
　　i. getPredecessor(N), which returns the next smaller node to N.
　　ii. getSuccessor(N), which returns the next larger node to N.
2. Try to assume that each node has a parent pointer, it makes the problem much easier.
3. Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
4. You would need two stacks to track the path in finding predecessor and successor node separately.


*/

