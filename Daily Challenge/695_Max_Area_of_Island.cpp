#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii;
    int m, n;
    int markIsland(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) {
            return 0;
        }
        
        grid[x][y] = 0;
        
        return 1 + markIsland(grid, x + 1, y) + markIsland(grid, x - 1, y)
                 + markIsland(grid, x, y + 1) + markIsland(grid, x, y - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = m ? grid[0].size() : 0;
        int x, y;
        int maxArea = 0;
        
        // Recursive approach
        // for(x = 0; x < m; ++x) {
        //     for(y = 0; y < n; ++y) {
        //         if(grid[x][y]) {
        //             maxArea = max(maxArea, markIsland(grid, x, y));
        //         }
        //     }
        // }
        
        // Iterative approach
        stack<pii> s;
        int tmp;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(x = 0; x < m; ++x) {
            for(y = 0; y < n; ++y) {
                if(grid[x][y]) {
                    tmp = 0;
                    
                    grid[x][y] = 0;
                    
                    s.push({x, y});
                    
                    while(!s.empty()) {
                        auto [i, j] = s.top();
                        s.pop();
                        ++tmp;
                        for(int k = 0; k < 4; ++k) {
                            int ii = i + dir[k][0];
                            int jj = j + dir[k][1];
                            
                            if(0 <= ii && ii < m && 0 <= jj && jj < n &&
                               grid[ii][jj]) {
                                
                                grid[ii][jj] = 0;
                                s.push({ii, jj});
                            }
                        }
                    }
                    
                    maxArea = max(maxArea, tmp);
                }
            }
        }
        
        return maxArea;
    }
};
