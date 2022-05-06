#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n; // Dimension of the matrix
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
        // If the result have been calculated before, return the previous result
        if(dp[x][y]) {
            return dp[x][y];
        }
        
        for(int i = 0; i < 4; ++i) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            // If the new index is out of bound or the next value is less than or
            // equal to the current value, skip the current round
            if(xx < 0 || xx >= m || yy < 0 || yy >= n || matrix[xx][yy] <= matrix[x][y]) {
                continue;
            }
            // Find the maximum increasing path starting at matrix[x][y]
            dp[x][y] = max(dp[x][y], dfs(matrix, dp, xx, yy));
        }
        
        // Add the current cell to the maximum increasing path
        return ++dp[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Get the dimension of the matrix
        m = matrix.size();
        n = m ? matrix[0].size() : 0;
        // Create the dp array
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int res = INT_MIN;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // Find the longest increasing path starting at each cell
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        
        return res;
    }
};
