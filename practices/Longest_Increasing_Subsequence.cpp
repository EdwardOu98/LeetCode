#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        int dp[n + 1]; // dp[i]: If we include the ith number, what's
                       // the longest increasing subsequence we can get
                       // from the first to i-1th number
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                if(nums[j-1] < nums[i-1]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            ++dp[i];
            res = max(dp[i], res);
        }
        
        
        return res;
    }
};
