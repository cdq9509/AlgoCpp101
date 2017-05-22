#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void print( vector<int>& in ){
		for (int i =0; i < in.size(); ++i ) {
			cout << in.at(i) << ","; 
		}
		cout << endl;
	}
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> out;
        combineDFS(n, k, 1, out, res);
        return res;
    }
    void combineDFS(int n, int k, int level, vector<int> &out, vector<vector<int> > &res) {
        if (out.size() == k) res.push_back(out);
        else {
            for (int i = level; i <= n; ++i) {
				cout << "input level " << level << " :";
				print( out ); 
                out.push_back(i);
                combineDFS(n, k, i + 1, out, res);
				cout << "output Level " << level << ":";
				print( out ); 
                out.pop_back();
            }
        }
    }
};

int main(void)
{
	Solution sol;
	vector< vector<int> > res = sol.combine(5, 3 ); 
	return 0;
}