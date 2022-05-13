#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<vector<bool>> visited;
    int m, n;

    bool dfs(vector<vector<int>>& obstacleGrid, int x, int y) {
        // If we are able to reach the bottom-right corner of the grids, return true
        if(x == m - 1 && y == n - 1) {
            return true;
        }

        // If y + 1 is in-bound, the grid on the x-th row and y+1-th column is not
        // an obstacle, and that grid has not been visited before
        if(y + 1 < n && !obstacleGrid[x][y+1] && !visited[x][y+1]) {
            res.push_back({x, y + 1});
            visited[x][y+1] = true;
            // If we are able to reach the bottom right corner
            // through this path, return true;
            if(dfs(obstacleGrid, x, y+1)) {
                return true;
            }
            // Otherwise, remove the last grid we add
            res.pop_back();
        }

        // If x + 1 is in-bound, the grid on the x+1-th row and y-th column is not
        // an obstacle, and that grid has not been visited before
        if(x + 1 < m && !obstacleGrid[x+1][y] && !visited[x+1][y]) {
            res.push_back({x + 1, y});
            visited[x+1][y] = true;
            // If we are able to reach the bottom right corner
            // through this path, return true;
            if(dfs(obstacleGrid, x+1, y)) {
                return true;
            }
            // Otherwise, remove the last grid we add
            res.pop_back();
        }

        // If we are not able to reach the bottom-right grid from the current
        // grid, return false
        return false;
    }
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) {
            return {};
        }
        m = obstacleGrid.size();
        n = m ? obstacleGrid[0].size() : 0;

        if(obstacleGrid[0][0]){
            return {};
        }

        visited = vector(m, vector<bool>(n, false));
        res.push_back({0, 0});
        return dfs(obstacleGrid, 0, 0) ? res : vector<vector<int>>();
    }
};
