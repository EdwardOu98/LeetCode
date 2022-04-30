#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int m, n;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
        // If the result have been calculated before, return the saved result
        if(dp[x][y]) {
            return dp[x][y];
        }

        for(int i = 0; i < 4; ++i) {
            int xx = x + dir[i][0], yy = y + dir[i][1];
            // If the index is out of bound, or the next element is smaller than
            // or equal to the current element, skip the current round
            if(xx < 0 || xx >= m || yy < 0 || yy >= n || matrix[xx][yy] <= matrix[x][y]) {
                continue;
            }
            dp[x][y] = max(dp[x][y], dfs(matrix, dp, xx, yy));
        }

        return ++dp[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); 
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = INT_MIN;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }

        return res;
    }
};
