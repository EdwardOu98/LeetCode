#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // Calculate the sum of the input array
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }

        // Calculate the difference between the target and
        // the sum
        int diff = sum - target;
        // If the difference is an odd number or the sum is
        // smaller than the target, return 0
        if(diff % 2 || diff < 0) {
            return 0;
        }

        diff /= 2;
        int dp[diff+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = diff; j >= nums[i]; --j) {
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[diff];
    }
};
