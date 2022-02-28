#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();

        for(int i = 1; i < n; ++i) {
            if(prices[i] > prices[i-1]) {
                profit = max(profit, prices[i] - prices[i-1]);
                prices[i] = prices[i-1];
            }
        }



        return profit;
    }
};
