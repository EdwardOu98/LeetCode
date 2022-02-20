#include <algorithm>	// std::sort
#include <vector>	    // std::vector

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // To solve this problem, we need to sort the intervals
        // array by their left bounds in accending order. Then, 
        // we compare the current interval with the left and right
        // bound stored in two variables. If both the left and right
        // bound of the current interval is larger than the previous
        // left and right bound, that means we have a new interval and
        // we need to update the left and right bound accordingly. 
        // Otherwise we only update the right bound to the maximum value
        // of the current right bound and the previous one. 
        int res = 0, left = -1, right = -1;
        
        sort(intervals.begin(), intervals.end());
        
        for(vector<int>& interval : intervals) {
            if((interval[0] > left) && (interval[1] > right)) {
                left = interval[0];
                ++res;
            }
            right = max(right, interval[1]);
        }
        
        return res;
    }
};
