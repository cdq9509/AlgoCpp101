/* Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
		if ( nums.size() <= 1 ) return true; 
		int maxRange = 0; 
		
        for (unsigned int i = 0; i < nums.size(); ++i) {
			if ( i > maxRange ) return false; 
			if ( i + nums.at(i) > maxRange ) maxRange = i + nums.at(i); 			
		}
		
		return true; 
		
    }
};