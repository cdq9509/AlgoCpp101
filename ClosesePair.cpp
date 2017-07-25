#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
//#include <string>

#include <cassert>
#include <cfloat>

using namespace std;

class Point {
  public: 
    float x;
    float y;
    Point(float ix = 0, float iy = 0) { x = ix; y = iy; }
};
bool CmpX(const Point &p1, const Point &p2) {
  return (p1.x < p2.x);
}
bool CmpY(const Point &p1, const Point &p2) {
  return (p1.y < p2.y);
}

static float dbgMinD = FLT_MAX; 
float Dist (const Point &p1, const Point &p2) {
  float d = ((p1.x-p2.x)*(p1.x-p2.x)) + ((p1.y-p2.y)*(p1.y-p2.y));
  if (d < dbgMinD) {
    cout << "*DBG*" << "prevMin" << dbgMinD << "update" << d << endl;
    cout << p1.x << "," << p1.y << endl;
    cout << p2.x << "," << p2.y << endl;
    dbgMinD = d; 
  }

  return d;
}
class Solution {
  private:

    void PrintVec( vector<Point> &in ) {
      for (int i = 0; i < in.size(); ++i) {
        cout << "(" << in.at(i).x << "," << in.at(i).y << ")";
      }
      cout << endl;
    }

    // Qx: sorted by x, Qy: sorted by y
    // Split according to mid of x
    float split(vector<Point> &Qx, vector<Point> &Qy,
        vector<Point> &Lx, vector<Point>&Rx,
        vector<Point> &Ly, vector<Point>&Ry)
    {
      // 0 to mid belongs to left plan
      int mid = (Qx.size()-1)/2;
      float midx = Qx.at(mid).x;

      for (int i = 0; i <= mid; ++i) { Lx.push_back(Qx.at(i)); }
      for (int i = mid+1; i < Qx.size(); ++i) { Rx.push_back(Qx.at(i)); }

      for(int i = 0; i < Qy.size(); ++i) {
        if ( Qy.at(i).x <= midx ) {
          Ly.push_back(Qy.at(i));
        } else {
          Ry.push_back(Qy.at(i));
        }
      }
      return midx;
    }

    float ClosetSplitPair(
        vector<Point> &py, float midx, float delta,// input
        vector<Point> &res )
    {
      vector<Point> Sy;
      float lb = midx - delta;
      float rb = midx + delta;
      for (int i = 0; i < py.size(); ++i) {
        if (py.at(i).x >= lb && py.at(i).x <= rb) {
          Sy.push_back(py.at(i));
        }
      }

      if (Sy.size() <= 1) return 0; 

      const int stride = 7; 
      float bestD = delta; 
      
      for (int i = 0; i < py.size(); ++i) {
        for (int j = 1; j < stride; ++j) {
          if (i + j < py.size()) {
            float d = Dist(py.at(i), py.at(i+j));
            if (d < bestD) { bestD = d; res.resize(0); res.push_back(py.at(i)); res.push_back(py.at(i+j));}
          }
        }
      }
      if (bestD == delta) return -1; 
      else return bestD;
    }

    // get closet pair from two sorted sequence
    float ClosetPair(
        vector<Point> &px,vector<Point>&py, //input
        vector<Point> &res)
    {
      assert( px.size() == py.size() );
      assert(px.size() >= 2);
      if (px.size()==2) {
        res.push_back(px.at(0));res.push_back(px.at(1));
        return Dist(px.at(0), px.at(1));}
      if (px.size()==3) {
        float d01 = Dist( px.at(0), px.at(1) );
        float d12 = Dist( px.at(1), px.at(2) );
        float d02 = Dist( px.at(0), px.at(2) );

        int i = -1, j = -1;
        float d = 0;
        if (d01 <= d12 && d01 <= d02) { i = 0; j = 1; d = d01; }
        else if (d12 <= d01 && d12 <= d02) { i = 1; j = 2; d = d12; }
        else { i = 0; j = 2; d = d02; }
        res.push_back(px.at(i)); res.push_back(px.at(j));
        return d;
      }

      vector<Point> Lx, Rx, Ly, Ry;
      // Split the sorted input into two half.
      float midx = split(px,py, Lx,Rx, Ly, Ry);
    
      // Left plane
      vector<Point> res1;
      float d1 = ClosetPair(Lx, Ly, res1);

      // Right plane
      vector<Point> res2;
      float d2 = ClosetPair(Rx, Ry, res2);

      float delta = min(d1, d2);
      vector<Point> res3;
      float d3 = ClosetSplitPair(py,midx, delta, res3);


      float d = 0;
      if (d1 <= d2 && d1 <= d3) { res = res1; d = d1; }
      else if (d2 <= d1 && d2 <= d3) { res = res2; d = d2; }
      else { res = res3; d = d3; }
      cout << d1 << "," << d2 << "," << delta << "," << d3 << "," << d << endl;
      return d;
    }

  public:
    float GetClosetPair(vector<Point> &in) {
      pair<Point,Point> p1, p2;
      vector<Point> px(in);
      vector<Point> py(in);
      sort(px.begin(), px.end(), CmpX);
      sort(py.begin(), py.begin(), CmpY);

      vector<Point> res; 
      float d = ClosetPair(px,py, res);
      cout << "try = "<< 2.34 << endl;
      cout << "minD = " << d << endl;
      PrintVec(res); 
      return d;
    }
};

int main(void)
{
  vector<Point> in;
  Solution sol;

  in.push_back( Point(1,2) );
  in.push_back( Point(3,6) );
  in.push_back( Point(0.5,4) );
  in.push_back( Point(5,8) );
  in.push_back( Point(4.2,4.6) );

  sol.GetClosetPair(in);

  cout << dbgMinD << endl;
  return 0;
}
