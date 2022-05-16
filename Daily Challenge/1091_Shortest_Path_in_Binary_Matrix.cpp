#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
typedef pair<int, int> pii;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // If the top-left or the bottom-right grid is 1, return -1
        if(grid[0][0] || grid[n-1][n-1]) {
            return -1;
        }
        
        // Record visited grids
        bool visited[n][n];
        memset(visited, false, sizeof(visited));
        
        visited[0][0] = true;
        queue<pii> q;
        q.push({0, 0});
        
        int dir[8][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
        int steps = 0;
        
        // BFS
        while(!q.empty()) {
            ++steps;
            int qSize = q.size();
            while(qSize--) {
                auto [x, y] = q.front();
                q.pop();
                
                // If we reached the bottom-right corner, return the steps
                if(x == n - 1 && y == n - 1) {
                    return steps;
                }
                
                for(int i = 0; i < 8; ++i) {
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    //If the new index is out of bound, or the corresponding grid
                    // is 1, or we have visited the grid before, skip the current
                    // round
                    if(xx >= 0 && xx < n && yy >= 0 && yy < n) {
                        if(!grid[xx][yy] && !visited[xx][yy]) {
                            q.push({xx, yy});
                            visited[xx][yy] = true;
                        }
                    }
                }
            }
        }
        
        
        return -1;
    }
};
