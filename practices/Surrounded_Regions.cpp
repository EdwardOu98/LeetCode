#include <vector>

using namespace std;

class Solution {
private:
    int M, N;
    void markBorder(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') {
            return;
        }
        
        board[x][y] = 'Z';
        markBorder(board, x - 1, y);
        markBorder(board, x + 1, y);
        markBorder(board, x, y - 1);
        markBorder(board, x, y + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        M = board.size(); 
        N = board[0].size();
        int x, y;
        
        // Mark all 'O' on the borders and the 'O's connected to
        // them as 'Z'
        for(x = 0; x < M; ++x) {
            if(board[x][0] == 'O') {
                markBorder(board, x, 0);
            }
            if(board[x][N-1] == 'O') {
                markBorder(board, x, N - 1);
            }
        }
        
        for(y = 0; y < N; ++y) {
            if(board[0][y] == 'O') {
                markBorder(board, 0, y);
            }
            if(board[M-1][y] == 'O') {
                markBorder(board, M-1, y);
            }
        }
        
        // Iterate through the board again. If the slot is 'O', 
        // mark it as 'X', if the slot = 'Z', mark it as 'O'
        for(x = 0; x < M; ++x) {
            for(y = 0; y < N; ++y) {
                board[x][y] = (board[x][y] == 'Z') ? 'O' : 'X';
            }
        }
    }
};
