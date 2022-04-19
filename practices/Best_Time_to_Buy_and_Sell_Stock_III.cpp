#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneBuy = INT_MAX; // Keep track of the lowest price of the first purchase
        int twoBuy = INT_MAX; // Keep track of the lowest price of the second purchase
        int oneBuyOneSell = 0; // Keep track of the maximum profit with one buy one sell
        int twoBuyTwoSell = 0; // Keep track of the maximum profit with two buy two sell
        
        for(int price : prices) {
            oneBuy = min(oneBuy, price);
            oneBuyOneSell = max(oneBuyOneSell, price - oneBuy);
            twoBuy = min(twoBuy, price - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, price - twoBuy);
        }
        
        return twoBuyTwoSell;
    }
};
