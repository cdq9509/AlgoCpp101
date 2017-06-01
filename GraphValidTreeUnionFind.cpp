

// The following is pretty smart  without implementing entire Union Find structure

#if 0 
// Union Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int x = find(roots, a.first), y = find(roots, a.second);
            if (x == y) return false;
            roots[x] = y;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};
#endif 

#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
  private:
    vector<int> parent;
    vector<int> sz;
  public:
    UnionFind(int n) {
      parent.resize(n); // ,-1);
      for (int i = 0; i < n; ++i) {parent.at(i) = i;} // this is inited for union to work
      sz.resize(n, 1);
    }
    
    int find(int p){
      // return group/component ID. it is represented as root index
      int r = p; 
      while (parent.at(r) != r) {
        r = parent.at(r);
      }
      return r; 
    }
    
    // Union is a key word in C
    void unioning(int p, int q) {
      int pid = find(p);
      int qid = find(q);
      if (pid == qid) return;
      
      if (sz.at(p) < sz.at(q)) {parent.at(pid) = qid;sz.at(pid) += sz.at(qid);}
      else {parent.at(qid) = pid; sz.at(qid) += sz.at(pid);}
    }
  
};

class Solution {

public:
    bool validTree(int n, vector<pair<int, int> >& edges) {

      UnionFind uf(n);
      vector<pair<int,int> >::iterator edgeIt; 
      for (edgeIt = edges.begin(); edgeIt != edges.end(); ++edgeIt) {
        if (uf.find(edgeIt->first) == uf.find(edgeIt->second)) {cout << "early terminate" << endl; return false;}
        uf.unioning(edgeIt->first, edgeIt->second);
      }
      
    // if |edges| != n - 1
      return edges.size() == n-1;       
    }
};

int main(void){
  Solution sol;
  
  int n = 4;
  vector<pair<int,int> > edges;
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(1,2));
  edges.push_back(make_pair(2,3));
  edges.push_back(make_pair(3,0));
  cout << "expect" << false << " Get" << sol.validTree(n, edges) << endl;
  
  n = 4;
  edges.resize(0);
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(1,2));
  // edges.push_back(make_pair(2,3));
  edges.push_back(make_pair(0,3));
  cout << "expect" << true << " Get" << sol.validTree(n, edges) << endl;
  
  
}
