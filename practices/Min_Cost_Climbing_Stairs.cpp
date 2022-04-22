#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);  // Put a zero at the end of the array
                            // to store the final result
        
        for(int i = 2; i <= n; ++i) {
            // The minimum cost to climb to the ith stair is the
            // minimum between the cost to climb to the i-1th 
            // and the i-2th stair plus the cost of the current
            // stair
            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
        }

        return cost[n];
    }
};
