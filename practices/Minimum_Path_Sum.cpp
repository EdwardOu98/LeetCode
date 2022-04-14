#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = grid[0][0];
        int i, j;
        int left, top;
        for(i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        for(j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for(i = 1; i < m; ++i) {
            for(j = 1; j < n; ++j) {
                top = dp[i-1][j] + grid[i][j];
                left = dp[i][j-1] + grid[i][j];
                dp[i][j] = min(top, left);
            }
        }
        
        return dp[m-1][n-1];
    }
};
