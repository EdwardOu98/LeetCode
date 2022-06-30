#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // To find the minimum moves required to equalize all
    // elements in the array, one method is to find the median
    // of the array elements, and sum up the difference between
    // all elements and the median
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // Sort input array
        sort(nums.begin(), nums.end());
        // Find the median
        int mid = nums[n / 2], count = 0;
        
        // Sum up the differences
        for(int i = 0; i < n; ++i) {
            count += abs(nums[i] - mid);
        }
        
        return count;
    }
};
