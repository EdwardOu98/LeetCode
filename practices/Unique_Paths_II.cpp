#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        int i, j;
        dp[0][0] = 1;
        
        for(i = 1; i < m; ++i) {
            dp[i][0] = !obstacleGrid[i][0] && dp[i-1][0];
        }
        
        for(j = 1; j < n; ++j) {
            dp[0][j] = !obstacleGrid[0][j] && dp[0][j-1];
        }
        
        for(i = 1; i < m; ++i) {
            for(j = 1; j < n; ++j) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
