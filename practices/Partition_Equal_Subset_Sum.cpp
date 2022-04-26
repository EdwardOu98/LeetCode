#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Calculate the sum of all elements in the input array
        // and find the maximum number in the array
        int sum = 0;
        int maxNum = 0;
        for(int num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }

        // If the sum is an odd number, then it can never be
        // divided into two parts whose sums are equal to each
        // other
        if(sum % 2) {
            return false;
        }

        // The sum of each part is half of the sum of the entire array.
        // If the maximum number in the array is greater than this number,
        // it's also not possible to divide the array into two parts with
        // equal sum
        int target = sum / 2;
        if(maxNum > target) {
            return false;
        }

        int n = nums.size();
        int i, j; // loop variables
        bool dp[n+1][target+1]; // dp[i][j] means whether we can reach the sum of j 
                                // when we are at the ith number of the array
        dp[0][0] = true; // Base case: we can always have a sum of zero even if we
                         // don't have any number
        
        // For the first column, as long as we don't choose any number, the sum can 
        // always be 0. Thus, the first column is all true
        for(i = 1; i <= n; ++i) {
            dp[i][0] = true;
        }

        // For the first row, if we don't have any numbere, the sum can never reach
        // j. Thus, the first row (except the first element) is all false
        for(j = 1; j <= target; ++j) {
            dp[0][j] = false;
        }

        for(i = 1; i <= n; ++i) {
            for(j = 1; j <= target; ++j) {
                // If we don't pick the ith number, then we need to check whether
                // we can get a sum of j with all numbers up to the i-1th number;
                // If we pick the current number, then we need to check whether
                // we can get a sum of j - nums[i-1] with the current number and
                // the numbers up to i-1th number. 
                dp[i][j] = dp[i-1][j];
                if(j - nums[i-1] >= 0) {
                    dp[i][j] |= dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][target];
    }
};
