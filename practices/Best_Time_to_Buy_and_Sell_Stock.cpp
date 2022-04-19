#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) {
            return 0;
        }
        int profit = 0;
        
        for(int i = 1; i < n; ++i) {
            // If today's stock price is higher than yestereday's price,
            // we calculate the profit by calculating the difference 
            // between the two prices. Then copy yesterday's price to today's
            // slot. 
            if(prices[i] > prices[i-1]) {
                profit = max(profit, prices[i] - prices[i-1]);
                prices[i] = prices[i-1];
            }
        }
        
        return profit > 0 ? profit : 0;
    }
};
