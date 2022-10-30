#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        queue<vector<int>> q;
        
        q.push({0, 0, 0, k}); // {x, y, path length, remaining obstacles to remove}
        
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            int x = v[0], y = v[1];
            
            // If the current cell is out of bound, continue
            if(x < 0 || x >= m || y < 0 || y >= n) {
                continue;
            }
            
            // If we reach the lower right corner of the grids, return the path length
            if(x == m - 1 && y == n - 1) {
                return v[2];
            }
            
            // If we see an obstacle
            if(grid[x][y] == 1) {
                // If we can remove the obstacle, remove it
                if(v[3] > 0) {
                    --v[3];
                }
                // Otherwise, skip the current cell
                else {
                    continue;
                }
            }
            
            // If the cell has been visited before and we can remove more obstacles
            // from the previous path, then we don't need to visit this cell again
            if(visited[x][y] != -1 && visited[x][y] >= v[3]) {
                continue;
            }
            visited[x][y] = v[3];
            
            q.push({x + 1, y, v[2] + 1, v[3]});
            q.push({x - 1, y, v[2] + 1, v[3]});
            q.push({x, y + 1, v[2] + 1, v[3]});
            q.push({x, y - 1, v[2] + 1, v[3]});
        }
        
        return -1;
    }
};
