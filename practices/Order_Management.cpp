#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Order {
    int id; // Order id
    int profit; // Order profit
    Order() {
        id = 0;
        profit = 0;
    }

    Order(int _id, int v, int w) {
        id = _id;
        profit = v + 2 * w;
    }

    // If two orders have the same profit, the one
    // with larger id lexicographic order should come
    // first. Otherwise, the one with smaller profit
    // comes first
    bool operator< (const Order& o1) {
        if(profit == o1.profit) {
            return id > o1.id;
        }
        return profit < o1.profit;
    }
} Order;

int main(void) {
    int n, m, v, w; // n - Total order count
                    // m - Acceptable order count
                    // v - Value of the order
                    // w - Weight of the order

    cin >> n >> m;
    Order orders[n];

    for(int i = 0; i < n; ++i) {
        cin >> v >> w;
        orders[i].id = i + 1;
        orders[i].profit = v + 2 * w;
    }

    // Sort the orders by their profit and the lexicographic
    // order of their id
    sort(orders, orders+n);

    vector<int> res;
    int k = n - 1;
    // Get the m orders with the largest profit
    while(m--) {
        res.push_back(orders[k--].id);
    }

    // Sort the selected order id
    sort(res.begin(), res.end());
    for(int id : res) {
        cout << id << " ";
    }

    return 0;
}