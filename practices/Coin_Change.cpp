#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        // Initialize the dp array
        for(int i = 0; i <= amount; ++i) {
            dp[i] = INT_MAX;
        }

        // When the amount of money we want is 0, 
        // we don't need any coins
        dp[0] = 0;

        for(int i = 0; i < n; ++i) {
            // Because we can pick each coin for multiple times
            for(int j = coins[i]; j <= amount; ++j) {
                // The value is valid only when dp[j-coins[i]] is
                // not INT_MAX
                if(dp[j - coins[i]] != INT_MAX) {
                    // Choose the smaller one between the current value
                    // and the dp[j - coins[i]] + 1
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
