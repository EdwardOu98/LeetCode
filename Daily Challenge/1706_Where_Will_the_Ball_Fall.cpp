#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    
    int findPos(vector<vector<int>>& grid, int row, int col) {
        // If we can reach the bottom of the grids, the column number
        // is where the ball reaches
        if(row == m) {
            return col;
        }
        
        int next = grid[row][col] == 1 ? col + 1 : col - 1;
        
        // There are 3 cases where we can't reach the next row
        // - We are at the left wall and the diagonal board goes from top-right to bottom-left
        // - We are at the right wall and the diagonal board goes from top-left to bottom-right
        // - The diagonal boards in the current and the adjacent cells form a V-shape
        if(next == -1 || next == n || grid[row][col] != grid[row][next]) {
            return -1;
        }
        
        // Otherwise, we can move to the next row
        return findPos(grid, row + 1, next);
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(); 
        n = grid[0].size();
        vector<int> res(n);
        
        for(int i = 0; i < n; ++i) {
            res[i] = findPos(grid, 0, i);
        }
        
        return res;
    }
};
