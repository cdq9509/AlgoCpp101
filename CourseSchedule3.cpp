#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

struct pqCmp {
  bool operator () (const vector<int>&a, const vector<int>& b) const { return a.at(0) < b.at(0); }
};
bool sortCmp(const vector<int>& a, const vector<int>& b) { return a.at(1) < b.at(1); }

class Solution {

public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort by deadline
        sort( courses.begin(), courses.end(), &sortCmp );
        // default use less and max heap. The other way make it a min heap.
        priority_queue< vector<int>, vector<vector<int> >, pqCmp> pq;
        int curEnd = 0;
        for (vector<vector<int> >::iterator it = courses.begin(); 
              it != courses.end();
              ++it) {
          if ( it->at(0) > it->at(1) ) { continue; } // invalid entry
          if ((curEnd + it->at(0)) <= it->at(1)) {
            curEnd += it->at(0);
            pq.push(*it);            
          } else if ( pq.top().at(0) > it->at(0) && 
                      curEnd - pq.top().at(0) + it->at(0) < it->at(1)) {
            curEnd -= (pq.top().at(0)-it->at(0)); pq.pop(); 
            pq.push(*it);
          }
        }
        return pq.size();
    }
};

int main(void) 
{
  Solution sol;
  return 0;
}