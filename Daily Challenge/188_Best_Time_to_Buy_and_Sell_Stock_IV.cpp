#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2 || k == 0) {
            return 0;
        }
        
        // If k is larger than half of the array size, 
        // then the problem becomes calculating the max
        // profit without concerning the limit of 
        // transactions
        if(k > n / 2) {
            int profit = 0;
            for(int i = 1; i < n; ++i) {
                profit += max(0, prices[i] - prices[i-1]);
            }
            return profit;
        }
        
        vector<int> buys(k + 1, INT_MIN);
        vector<int> sells(k + 1, 0);
        for(int price : prices) {
            for(int i = k; i >= 1; --i) {
                sells[i] = max(sells[i], buys[i] + price);
                buys[i] = max(buys[i], sells[i-1] - price);
            }
        }
        
        return sells[k];
    }
};
