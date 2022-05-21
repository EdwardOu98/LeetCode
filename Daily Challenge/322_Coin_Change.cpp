#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp array, where dp[i] is the minimum amount of
        // coins required to get i amount of money
        int dp[amount + 1];
        for(int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
        }
        // To get 0, we don't need any coins.
        dp[0] = 0;
        
        // For each of the coins, we calculate the minimum
        // number of coins required to reach the amount of
        // i. 
        for(int& coin : coins) {
            for(int i = coin; i <= amount; ++i) {
                // dp's value is meaningful only when it's
                // not INT_MAX
                if(dp[i - coin] != INT_MAX) {
                    // The current value of dp is minimum between
                    // its current value (we don't pick up the
                    // current coin) or dp[i - coin] + 1 (we pick
                    // up the current coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
