#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/* Problem:
 * A clothing store has a ties, b pants, c caps, and d shirts. The owner wants
 * to sell them in combos. There are three combinations: a tie + a shirt, 
 * a pants + a shirt, and a cap + a shirt. Selling a tie-shirt combo can earn e
 * dollars, a pants-shirt combo can earn f dollars, and a cap-shirt combo can
 * earn g dollars. Find the maximum profit that can be made. 
 */

 typedef long long LL;
 typedef pair<LL, LL> pLL;

 static bool comp(pLL& a, pLL& b) {
    return a.first > b.first;
 }

 int main(void) {
    LL a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    vector<pLL> combos;
    // Because all combinations requires a shirt, we can simply associate the
    // profit of each combo with the other item in the combo. 
    combos.push_back({e, a});
    combos.push_back({f, b});
    combos.push_back({g, c});
    // Sort the combos based on their profit
    sort(combos.begin(), combos.end(), comp);

    LL maxProfit = 0;
    for(auto& [profit, num] : combos) {
        // If the current combo's item is more than the count of remaining shirts,
        // the maximum profit can be made is limited by the count of shirts. Calculate
        // the profit made by this combi and terminate the loop because there are no
        // shirts left
        if(num >= d) {
            maxProfit += d * profit;
            d = 0;
            break;
        }
        else{
            maxProfit += num * profit;
            d -= num;
        }
        
    }

    cout << maxProfit << endl;

    return 0;
 }
