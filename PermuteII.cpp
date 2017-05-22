/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        void print( vector< vector<int> >& in ) {
            cout << "########## total "<< in.size() << "################" << endl; 
            for (unsigned int i = 0; i < in.size(); ++i) {
                vector<int> words = in.at(i); 
                for(unsigned j = 0; j< words.size(); ++j) {
                    cout << words.at(j) << ","; 
                }
                cout << endl; 
            }
        }
        
            vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> out;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        permuteUniqueDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (level >= num.size()) { res.push_back(out); print(res); }
        else {
            for (int i = 0; i < num.size(); ++i) {
                if (visited[i] == 0) {
                    if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) continue;
                    visited[i] = 1;
                    out.push_back(num[i]);
                    permuteUniqueDFS(num, level + 1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
        
#if 0  
    /* The issue is a unique permultation of n-1, adding x[n] may cause duplicates
    ########## total 3################
2,1,1,
1,2,1,
1,1,2,

insert 2 will have two duplicate [2,1,2,1]
    */
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > res;
        if (nums.size() <= 1) {res.push_back(nums); return res;}
        
        int val = nums.back();
        nums.pop_back(); 
        
        vector< vector<int> > tres = permuteUnique( nums );
        
        vector<int> tmp; 
        for (unsigned int i = 0; i <tres.size(); ++i ) {
          tmp = tres.at(i);
          for (unsigned int j = 0; j < tmp.size(); ++j) {
            vector<int> tt = tmp;
            if ( j > 0 && tt.at(j-1) == val ) continue; 
            tt.insert( tt.begin() + j, val );
            res.push_back( tt );
          }
          if ( tmp.back() == val ) continue; 
          tmp.push_back(val);
          res.push_back(tmp);
        }
        
        print(res);
        return res; 
    }
#endif     
};


int main(void) 
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  
  Solution sol;
  sol.permuteUnique(nums);
  
  return 0;
}