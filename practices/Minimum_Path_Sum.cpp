#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Initialize first column
        for(int i = 1; i < m; ++i) {
            grid[i][0] += grid[i-1][0];
        }

        // Initialize first row
        for(int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j-1];
        }

        // For each cell, the minimum path sum to this cell
        // is the minimum between the left and top cell plus
        // the current cell
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};
