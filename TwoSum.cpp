/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		if ( nums.size() <= 1 ) return res;
		
		// value vs. index
		// For repeated number, using [] is better than insert.
		// insert may fail if key is already there. 
		map<int, int> lut; 
		for (unsigned int i = 0; i < nums.size(); ++i) {
			lut[nums.at(i)] = i;
		}

		map<int,int>::iterator it;
		for (unsigned int i = 0; i < nums.size(); ++i) {
			if ( (it = lut.find( target - nums.at(i) )) != lut.end() ) {
				res.push_back(i);
				res.push_back(it->second); 
			}
		}
		
		return res; 
    }
};