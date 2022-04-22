#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m][n];
        // If the last cell of the dungeon contains a negative
        // number val, the knight needs to at least have 1 - val
        // to survive. In other cases, he only needs 1 life to
        // survive
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
        
        int i, j;
        
        // On the last row, since we can only move from left to
        // right, so the minimum life of each cell depends only
        // on the minimum life required by the next cell
        for(i = n - 2; i >= 0; --i) {
            dp[m-1][i] = max(1, dp[m-1][i+1] - dungeon[m-1][i]);
        }
        
        // On the last column, since we can only move from top
        // to bottom, so the minimum life of each cell depends
        // only on the minimum life required by the next cell
        for(i = m - 2; i >= 0; --i) {
            dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);
        }
        
        // For all other cells, the minimum life depends on the
        // minimum between the right and bottom requireement. 
        for(i = m - 2; i >= 0; --i) {
            for(j = n - 2; j >= 0; --j) {
                dp[i][j] = min(max(1, dp[i][j+1] - dungeon[i][j]), 
                               max(1, dp[i+1][j] - dungeon[i][j]));
            }
        }
        
        return dp[0][0];
    }
};
