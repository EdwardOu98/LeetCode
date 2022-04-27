#include <vector>

using namespace std;

class Solution {
public:
    // Because all cells use only 1 bit (either 1 or 0) to represent its
    // current value, we can use the second bit to represent its next state.
    // In this case, we can first store the next state along with the current
    // state in the same cell and update all cells by shifting their values
    // 1 bit to the right. 
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int count;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                count = 0;
                for(int p = max(0, i-1); p < min(m, i+2); ++p) {
                    for(int q = max(0, j - 1); q < min(n, j+2); ++q) {
                        count += board[p][q] & 1;
                    }
                }
                
                if(count == 3 || count - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
