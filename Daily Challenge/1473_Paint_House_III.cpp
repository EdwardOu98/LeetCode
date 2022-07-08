#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCost = 1e6 + 1;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(target+1, vector<int>(n, maxCost)));
        int color, house, neighborhoods;
        
        for(color = 1; color <= n; ++color) {
            if(houses[0] == color) {
                // If the colorof house 0 is the same as the current
                // color, we don't need to paint it
                memo[0][1][color - 1] = 0;
            }
            else if(!houses[0]) {
                // If house 0 is not painted, then the cost to paint
                // the house is the same as the one in cost array
                memo[0][1][color - 1] = cost[0][color - 1];
            }
        }
        
        for(house = 1; house < m; ++house) {
            for(neighborhoods = 1; neighborhoods <= min(target, house + 1); ++neighborhoods) {
                for(color = 1; color <= n; ++color) {
                    // If the house is already painted and color
                    // is different, skip the current round
                    if(houses[house] && color != houses[house]) {
                        continue;
                    }
                    
                    int currCost = maxCost;
                    
                    // Iterate through all possible color of previous house
                    for(int prevColor = 1; prevColor <= n; ++prevColor) {
                        if(prevColor != color) {
                            // If adjacent house has different color, the current cost is the cost
                            // used to paint the last neighborhood
                            currCost = min(currCost, memo[house-1][neighborhoods-1][prevColor-1]);
                        }
                        else {
                            // If the adjacent house has same color, the current cost is the cost
                            // used to paint the current neighborhood
                            currCost = min(currCost, memo[house-1][neighborhoods][color-1]);
                        }
                    }
                    
                    // update the minimum cost to paint the house
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[house][neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
        }
        
        int minCost = maxCost;
        for(color = 1; color <= n; ++color) {
            minCost = min(minCost, memo[m-1][target][color-1]);
        }
        
        return minCost == maxCost ? -1 : minCost;
    }
};
