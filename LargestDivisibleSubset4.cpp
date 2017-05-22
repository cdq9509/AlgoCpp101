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
	// assume it is sorted, if the largest one can divide, then the set is valid. This reduce condition check.
	// 
	// At elem I: we store 
	// 1. max size of a subset that includes num[I] 
	// When adding a new elem, we move back to find out who can divide, then we know the max size of subset
	//
	// find the max out of this can give me the answer of the max size of subset.
	
	// Now if I add the max size of subset from num[0 to I-1], 
	// then I can get the max number even faster, but I don't really need to know the max number
	// so far, I need to know the subset, which can be obtained by storing the parent of that set. 
	//  
	
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
		
			for(vector<int>::iterator i = nums.begin(); i!= nums.end(); ++i) {
		cout << *i << endl;
	}
		
		// Pair:( Max Size of a subset that includs num[I],
		// Index of previous element in that subset)
		vector< pair<int,int> > state;
		state.resize( nums.size() );
		state.at(0) =( make_pair(1,-1) ); // initial condition
		
		unsigned int maxSizeSoFar = 1; 
		int parentOfMaxSet = 0; 
		
		for (unsigned int i = 1; i < nums.size(); ++i) {
			unsigned int maxSizeIncludesI = 1; 
			bool hasParent = false;
			for (int j = i-1; j>=0; --j) {
				if ( nums.at(i) % nums.at(j) == 0 ) {
					state.at(i).first = state.at(j).first + 1;
					state.at(i).second = j;
					maxSizeIncludesI = state.at(i).first;
					hasParent = true; 
					break; 
				}
			}
			if (!hasParent) state.at(i) =  make_pair(1, -1) ;
			
			if ( maxSizeIncludesI > maxSizeSoFar ) {
					maxSizeSoFar = maxSizeIncludesI;
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