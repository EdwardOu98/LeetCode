#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    void markIslands(vector<vector<char>>& grid, int i, int j) {
        // If the indices are out of bound or the current grid is not '1',
        // exit the function
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '*'; // Mark the current grid as '*' to prevent repeetitive visits
        markIslands(grid, i + 1, j);
        markIslands(grid, i - 1, j);
        markIslands(grid, i, j + 1);
        markIslands(grid, i, j - 1);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int islandCount = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    markIslands(grid, i, j);
                    ++islandCount;
                }
            }
        }
        
        return islandCount;
    }
};
