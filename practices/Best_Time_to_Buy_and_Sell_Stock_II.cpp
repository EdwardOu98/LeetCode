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
            // To buy and then immediately sell on the same day means doing nothing
            // on that day. When the day begins, you have nothing. You purchased the
            // stock and then immediately sell it, you still have nothing at the end
            // of the day.
            // To sell and then buy on the same day is similar. When the day begins 
            // you have certain amount of money. You sell it at that day and then 
            // immediately purchase on the same day, you still have the same amount
            // of money. 
            // Thus, to calculate the maximum profit, we can simply sum up difference
            // between each day. When the difference is smaller than 0, we add 0 to 
            // the profit. When it's greater than 0, we simply add the difference to
            // the profit. 
            profit += max(0, prices[i] - prices[i-1]);
        }
        
        return profit;
    }
};
