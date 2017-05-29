#include <iostream>
#include <vector>
#include <set>
// #include <set>

using namespace std;

class Solution {
  public:
  	void print( vector<int>& in ){
		for (int i =0; i < in.size(); ++i ) {
			cout << in.at(i) << ","; 
		}
		cout << endl;
	}
  
  set< vector<int> > permuteHelper( vector<int> & num ) {
    set< vector<int> > res; 
    if ( num.size() <= 1 ) { res.insert( num ); return res; }
    
    int elem = num.back();
    num.pop_back(); 
    
    set< vector<int> > tres = permuteHelper( num );
    // set does not have access
    for (set< vector<int> >::iterator it = tres.begin(); it != tres.end(); ++it) {
      vector<int> t = *it;
      vector<int> tt; 
      for ( unsigned int i = 0; i < t.size(); ++i ) {
        tt = t; 
        tt.insert( tt.begin() + i, elem ); 
        if ( res.find( tt ) == res.end() ) {res.insert( tt );}
      }
      tt = t; 
      tt.push_back(elem);
      if ( res.find( tt ) == res.end() ) {res.insert( tt );}
      
    }
    
  }
   vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        set< vector<int> >  tres = permuteHelper(num);
        
        for (set< vector<int> >::iterator it = tres.begin(); it != tres.end(); ++it) {
          vector<int> tt = *it; 
          print(tt);
          res.push_back(tt);
        }
        return res;
    }
};

int main(void) 
{
  vector<int> n;
  n.push_back(1);
  n.push_back(1);
  n.push_back(2);
  // n.push_back(2);
  
  Solution sol;
  sol.permuteUnique(n);
  return 0; 
}