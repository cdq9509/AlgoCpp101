class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res;
        unsigned int left = 0, right = numbers.size() - 1; 
		
		while ( left < right ) {
			int sum = numbers.at(left) + numbers.at(right);
			if ( sum == target ) {  res.push_back(left+1); res.push_back(right+1); return res; }
			else if ( sum > target ) { --right;}
			else {++left;}
		}
		return res; 
    }
};