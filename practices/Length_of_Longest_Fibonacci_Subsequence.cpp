#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0; // The maximum length of the fibonacci series
        int dp[n-1][n]; // Because i  is strictly less than j, we can
                        // set the first dimention of the array to n - 1
        memset(dp, 0, sizeof(dp));
        int i, j, k;    // Loop variables
        int sum;
        for(k = 2; k < n; ++k) {
            i = 0;
            j = k - 1;
            while(i < j) {
                sum = arr[i] + arr[j];
                // If the sum is nums[k], we have a fibonacci relation.
                // Update the dp value and the maxLen
                if(sum == arr[k]) {
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                    ++i;
                    --j;
                }
                else if(sum < arr[k]) {
                    ++i;
                }
                else {
                    --j;
                }
            }
        }

        // If maxLen is never updated in the loop, it means that the
        // input array doesn't contain any fibonacci relations and, 
        // thus, return 0. Otherwise, we need to return maxLen + 2
        // because for maxLen = 1, the fibonacci series actually 
        // contains 3 numbers. 
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};
