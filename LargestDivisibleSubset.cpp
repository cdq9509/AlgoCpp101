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

// DP: store max size of a subset that includs num[i} does NOT work
//     4 8 10 240. 240 divides both 10 and 8. And 240 choose 10. This is wrong
// 
//     1. store max size of a subset for num[0 to I-1]. (This allows DP update). 
//     2. store the root/parent of a max subset that includes I-1. This is needed (plus the starting point, this allows us to backtrack)
	
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std; 

class Solution {
public:


    vector<int> largestDivisibleSubset(vector<int>& nums) {
		
		if ( nums.size() <= 0) return nums;
		sort( nums.begin(), nums.end());
		
		vector< pair<unsigned int,int> > state;
		state.resize( nums.size() );
		state.at(0) =( make_pair(1,-1) ); // initial condition
		
		unsigned int maxSizeSoFar = 1; 
		int parentOfMaxSet = 0; 
		
		for (unsigned int i = 1; i < nums.size(); ++i) {
			state.at(i) = make_pair( 1, -1); 
			
			for (int j = i-1; j>=0; --j) {
				if ( nums.at(i) % nums.at(j) == 0 && state.at(i).first < state.at(j).first +1 ) {
					state.at(i).first = state.at(j).first + 1;
					state.at(i).second = j;					 
				}
			}
			
			if ( state.at(i).first > maxSizeSoFar ) {
					maxSizeSoFar = state.at(i).first;
					parentOfMaxSet = i; 
			}
		}
		
		vector<int> finalRes;		
		while ( parentOfMaxSet >= 0 ) {
			finalRes.push_back( nums.at(parentOfMaxSet) );
			parentOfMaxSet = state.at(parentOfMaxSet).second;
		}
		
		return finalRes; 
    }
};

int main(void)
{
	Solution sol;
	vector<int> in;
	in.push_back(8);
	in.push_back(4);
	in.push_back(10);
	in.push_back(240);
	vector<int> res = sol.largestDivisibleSubset(in);
	for(vector<int>::iterator i = res.begin(); i!= res.end(); ++i) {
		cout << *i << endl;
	}
	
	return 0;
}