/*
 Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)

Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/

// brute force: find all subsets, in each subset, need to list all permutations and verify if they satify condition
// 2nd thought: when growing subset, check to see the adding element satisfy condition

#include <vector>

using namespace std; 

class Solution {
public:

	// return all subset that satisfy condition
	vector< vector<int> > helper( vector<int>& in ) {
			vector< vector<int> > finalRes; 
			if (in.size() <= 1 ) {
				finalRes.push_back(in); return finalRes;
			}
	
			int elem = in.back();
			in.pop_back();
			vector< vector<int> > res = helper( in ); 
			for (unsigned int i = 0; i < res.size(); ++i) {
				vector<int> aSet = res.at(i);
				bool isElemAdded = true; 
				for (unsigned int j = 0; j < aSet.size(); ++j) {
					if (aSet.at(j) % elem != 0 && elem % aSet.at(j) != 0) {
						isElemAdded = false; break;
					}
				}
				finalRes.push_back(aSet); // If I don't do this, I prematurely prune some set
				if (isElemAdded) { aSet.push_back( elem ); finalRes.push_back( aSet ); }
			}
			vector<int> tRes; tRes.push_back(elem); finalRes.push_back(tRes);
			
			return finalRes; 			
	}
	
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
		vector< vector<int> > res = helper(nums);
		unsigned int maxSize = 0;
		vector<int> finalRes; 
		for (unsigned int i = 0; i < res.size(); ++i) {
			if ( res.at(i).size() >= maxSize ) { finalRes = res.at(i); maxSize = res.at(i).size();}
		}
		return finalRes; 
    }
};

int main(void)
{
	Solution sol;
	vector<int> in;
	in.push_back(1);
	in.push_back(2);
	sol.largestDivisibleSubset(in);
	return 0;
}