#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int m, n; // dimension of the matrix
    int markAndGetArea(vector<vector<int>>& grid, int x, int y) {
        // If the index is out of bound or the current cell has been
        // marked before, return 0 as the area for this cell
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
            return 0;
        }

        grid[x][y] = 2; // Use a number other than 0 and 1 to mark
                        // the cell as visited

        return 1 + markAndGetArea(grid, x + 1, y) + markAndGetArea(grid, x - 1, y)
                 + markAndGetArea(grid, x, y + 1) + markAndGetArea(grid, x, y - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for(int x = 0; x < m; ++x) {
            for(int y = 0; y < n; ++y) {
                if(grid[x][y] == 1) {
                    int area = markAndGetArea(grid, x, y);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
