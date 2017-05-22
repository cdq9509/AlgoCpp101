/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
 class Solution {
public:
    // return 1 if new Point in lies betwee s0 and s1
    int checkLine( Point& in, Point & s, int dx, int dy, long long cross) {
        
        if (dx == 0) return (in.x == s.x)? 1: 0; 
        long long nc = ((long long) dx)*in.y - ((long long) dy)*in.x;
        return (cross == nc)? 1: 0;
    }
    
    int maxPoints(vector<Point>& points) {
        int n = points.size(); 
        if ( n <= 2 ) return n; 
        int ma_size = 2; 
        for (int i = 0; i < n; i++) {
            int duplicate = 0; 
            int isStartNPoint = 0;
            int lineSet = 1; 
            for (int j = i + 1 ; j < n; j++) {
                // Now find out the number of points that lies in Point i and Point j
                // only need to look at points starting from j 
                if ( points.at(i).x == points.at(j).x && points.at(i).y == points.at(j).y && isStartNPoint == 0) {
                    // Special case: start with N repetition point. 
                    isStartNPoint = 1;
                    lineSet++; 
                    continue;
                }
                int line_set = lineSet + 1 ; 
                int delta_x = points.at(j).x - points.at(i).x;
                int delta_y = points.at(j).y - points.at(i).y;
                long long cross   = ( (long long) points.at(j).x * points.at(i).y) - ( (long long) points.at(j).y) * points.at(i).x;
                // cout << i << "," << j << ",d" << delta_x << "," << delta_y << "," << cross << "endl"; 
                for (int k = j + 1; k < n; k ++) {
                    line_set += checkLine( points.at(k), points.at(i),delta_x, delta_y, cross); 
                }
                ma_size = max( ma_size, line_set); 
            }
        }
        return ma_size; 
    }
};
