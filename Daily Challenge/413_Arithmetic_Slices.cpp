#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        // vector<int> dp(n, 0);
        // dp[2] = ((nums[2] - nums[1]) == (nums[1] - nums[0])) ? 1 : 0;
        // int res = dp[2];
        int curr = 0, prev = ((nums[2] - nums[1]) == (nums[1] - nums[0])) ? 1 : 0;
        int res = prev;
        for(int i = 3; i < n; i++){
            curr = ((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])) ? prev + 1 : 0;
            prev = curr;
            res += curr;
        }
        return res;
    }
};
