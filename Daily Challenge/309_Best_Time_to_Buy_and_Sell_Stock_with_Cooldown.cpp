#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // If the prices array is too short, return 0
        if(n < 2) {
            return 0;
        }
        
        int dp[n]; // dp[i] represents the maximum profit we can make by the end of the ith day (0-indexed)
        memset(dp, 0, sizeof(dp)); // Initialize dp array;
        dp[1] = max(prices[1] - prices[0], 0); // the maximum profit we can make on the first day is larger one
                                               // between 0 and the profit we gain by buying on day 0 and selling
                                               // on day 1
        int maxDiff = INT_MIN; // Records the maximum difference between the current maximum profit
                               // and the price on the day we buy a share
        
        for(int i = 0; i < n; ++i) {
            if(i < 2) {
                maxDiff = max(maxDiff, -prices[i]); // Find the cheaper buy-in price on the first two days
            }
            else {
                // The max profit we can make starting from the third day is one of the following situation:
                // 1. If the day is a buy day, the maximum profit we can make is the same as the previous day
                // 2. The same situation goes for a cool-down day
                // 3. If it's a sell day, the maximum profit we can make is the difference between the current
                //    stock price and the minimum buy-in price (maxDiff). 
                dp[i] = max(dp[i-1], maxDiff + prices[i]);
                // If we decide to buy-in today, then yesterday must be a cool-down day. Thus, the minimum
                // buy-in price should either stay the same or the profit we made two days ago minus the
                // current price
                maxDiff = max(maxDiff, dp[i-2] - prices[i]);
            }
        }
        
        return dp[n-1];
    }
};
