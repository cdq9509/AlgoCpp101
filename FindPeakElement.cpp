// this one does not work in one shot
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1; 
        int mid; 
        while ( left <= right ) {
            mid = left + ( right - left )/2;
            if ( (mid < 1 || nums.at(mid)>= nums.at(mid-1)) && 
                 ( mid >= nums.size() - 1 || nums.at(mid) >= nums.at(mid+1)) ) {
                return mid;
            } else if ( mid >=1 && nums.at(mid) < nums.at(mid-1) ) {
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }
        return -1; 
    }
};


// this works in one shot. 
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0; 
        for (int i = 0; i < nums.size()-1; i++) {
            if ( nums.at(i) > nums.at(i+1) ) return i;
        }
        return nums.size()-1; 
    }
};