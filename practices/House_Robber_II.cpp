#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int robMax(vector<int>& nums, int start, int end) {
        
        int odd = 0, even = 0;
        for(int i = start; i <= end; ++i) {
            if(i % 2) {
                odd = max(even, odd + nums[i]);
            }
            else {
                even = max(odd, even + nums[i]);
            }
        }

        return max(odd, even);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return nums[0];
        }

        if(n == 2) {
            return max(nums[0], nums[1]);
        }

        // If we start robbing from the first house, then we
        // have to stop at the n-2th house (zero-indexed). 
        // Similarly, if we want the last house to be robbed,
        // we have to start at the second house. And the 
        // maximum amount we can rob is the maximum between the
        // two above cases. 
        return max(robMax(nums, 0, n - 2), robMax(nums, 1, n - 1));
    }
};
