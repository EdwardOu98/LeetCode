#include <utility>
#include <stack>

using namespace std;

class StockSpanner {
private:
    typedef pair<int, int> pii;
    stack<pii> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!prices.empty() && prices.top().first <= price) {
            count += prices.top().second;
            prices.pop();
        }
        
        prices.push({price, count});
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
