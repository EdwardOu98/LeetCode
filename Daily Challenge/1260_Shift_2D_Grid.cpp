#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                int newRow = (row + (col + k) / n) % m;
                int newCol = (col + k) % n;
                
                res[newRow][newCol] = grid[row][col];
            }
        }
        
        return res;
    }
};
