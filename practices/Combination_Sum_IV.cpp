#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[target+1]; // dp[i] means the number of combinations
                                   // that can sum up to i
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // Base case: to sum up with 0, only one combination works
                   // which is choose nothing

        int n = nums.size();
        for(int i = 1; i <= target; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
