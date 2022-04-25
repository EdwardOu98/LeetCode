using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        // For cells in the first column, there's only
        // one path to get to them, which is from their
        // top cells
        for(int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        // For cells in the first row, there's only
        // one path to get to them, which is from their
        // left cells
        for(int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }

        // For other cells, the number of paths to reach
        // them is sum of the paths to reach their top
        // and left cells
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
