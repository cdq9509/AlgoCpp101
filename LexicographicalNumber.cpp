/*
 Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
    }
};


// recursive each digit


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            helper(i, n, res);
        }
        return res;
    }
    void helper(int cur, int n, vector<int>& res) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++i) {
            if (cur * 10 + i <= n) {
                helper(cur * 10 + i, n, res);
            } else break;
        }
    }
};