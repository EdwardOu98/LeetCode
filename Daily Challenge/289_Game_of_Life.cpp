#include <vector>
#include <algorithm>

using namesapce std;

class Solution {
public:
    // Because all cells use only 1 bit (either 1 or 0) to represent its
    // current value, we can use the second bit to represent its next state.
    // In this case, we can first store the next state along with the current
    // state in the same cell and update all cells by shifting their values
    // 1 bit to the right. 
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size(), i, j, k, l;
        int count;  // record the number of live cells in the neighbors of the
                    // current cell
        
        for(i = 0; i < m; ++i) {
            for(j = 0; j < n; ++j) {
                count = 0;
                for(k = max(i - 1, 0); k < min(i + 2, m); ++k) {
                    for(l = max(j - 1, 0); l < min(j + 2, n); ++l) {
                        // Update count value based on the cells' current state
                        count += board[k][l] & 1;
                    }
                }
                
                // count == 3: A dead cell with 3 neightbors or a live cell
                // with 2 neightbors. 
                // count - board[i][j] == 3: A live cell with 3 neighbors
                // Both cases will result in the current cell surviving through
                // the next generation
                if((count == 3) || ((count - board[i][j]) == 3)) {
                    board[i][j] |= 2;
                }
            }
        }
        
        for(i = 0; i < m; ++i) {
            for(j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
