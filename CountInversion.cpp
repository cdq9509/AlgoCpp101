#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int CntInv(vector<int> &in) {
      if (in.size() <= 1) return 0;
      vector<int> tmp(in.size()); // for swap in merge
      return SortAndCntInv(in, 0, in.size() - 1, tmp);
    }

  private:

    void PrintVec(vector<int> &in) {
      for (int i=0; i < in.size(); ++i) {
        cout << in.at(i) << "," ; 
      }
      cout << endl;
    }

    // This is a merge sort
    int SortAndCntInv(vector<int> &in, int s, int e, vector<int> &tmp) {
      if (s == e) return 0; 

      int mid = s + (e-s)/2; 

      int cnt = 0;
      cnt += SortAndCntInv(in, s, mid, tmp);
      cnt += SortAndCntInv(in, mid+1, e, tmp);
      cnt += MergeAndCntSplitInv(in, s, mid, e, tmp);

      cout << "s" << s << ", e" << e << ", cnt " << cnt << endl; 
      return cnt; 
    }

    // s to  mid is already sorted.
    // mid+1 to e is also sorted. 
    int MergeAndCntSplitInv(vector<int>& in, int s, int mid, int e, vector<int> &tmp) {
      int cnt = 0; 
      int ci = s; // current index
      int left = s;
      int right = mid+1;
#ifdef DEBUG     
      cout << "DEBUG:####################" << endl;
      PrintVec(in);
#endif
      while ( ci <= e ) {
        if ( (left <= mid && right <=e && in.at(left) > in.at(right)) ||
            left > mid ) {
          tmp.at(ci) = in.at(right);
          if (left <= mid && right <=e && in.at(left) > in.at(right) ) { cnt += ( mid - left + 1);}
          ++right;
        } else {
          tmp.at(ci) = in.at(left);
          ++left;
        }
        ++ci;
      }

      for (int i = s; i < e; ++i) { in.at(i) = tmp.at(i);}
#ifdef DEBUG
      PrintVec(in);
      cout << "s" << s << ", m" << mid << ", e" << e << ", cnt " << cnt << endl; 
      cout << "DEBUG_END:####################" << endl;
#endif      
      return cnt;
    }
};

int main(void)
{
  Solution sol;
#if 0 
  int arr[] = { 1, 2, 3, 5, 4, 6 };
  vector<int> in( arr, arr+sizeof(arr)/sizeof(arr[0]));

  sol.CntInv(in);
#endif
  int arr2[] = { 1, 3, 5, 2, 4, 6 };
  vector<int> in2( arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
  sol.CntInv(in2);

  return 0;
}
