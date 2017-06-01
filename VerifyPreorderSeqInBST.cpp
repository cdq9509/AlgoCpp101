/* Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

// my thought:
// root is first element
// array would be: root [left subtree] [ right subtree]
// all left should be smaller than root and all right should be larger than root
// So, we find the first pivot location such that array[p] > root
// split the array into two and verify each satisfy condition w.r.t. root
// then check left and right are preorder as well. 
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {

    }
};