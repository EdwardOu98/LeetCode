#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int N;
    vector<vector<string>> res;
    vector<string> board;
    
    bool isValid(int x, int y) {
        int i = x - 1, j = y;
        
        // Check the vertical direction
        while(i >= 0) {
            if(board[i][y] == 'Q') {
                return false;
            }
            --i;
        }
        
        // Check the top-left diagonal
        i = x - 1, j = y - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') {
                return false;
            }
            --i;
            --j;
        }
        
        // Check the top-right diagonal
        i = x - 1, j = y + 1;
        while(i >= 0 && j < N) {
            if(board[i][j] == 'Q') {
                return false;
            }
            --i;
            ++j;
        }
        
        return true;
    }
    
    void dfs(int row) {
        // If we managed to put a queen on every row, add the current 
        // board to the result array
        if(row == N) {
            res.push_back(board);
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            // If we can put a queen at the current position
            if(isValid(row, i)) {
                // Put the queen at the current grid
                board[row][i] = 'Q';
                // Try to put a queen in the next row
                dfs(row + 1);
                // Reset the board to the original state
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        board = vector<string>(n, string(n, '.'));
        dfs(0);
        return res;
    }
};
