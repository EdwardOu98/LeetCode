#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int dp[nums1.size() + 1][nums2.size() + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = nums1.size() - 1; i >= 0; --i) {
            for(int j = nums2.size() - 1; j >= 0; --j) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res;
    }
};
