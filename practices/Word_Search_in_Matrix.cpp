#include <vector>

using namespace std;

class Solution {
private:
    int ROW, COL, LEN;
    bool backtracking(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        if(idx >= LEN) {
            return true;
        }
        if(row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != word[idx]) {
            return false;
        }

        char c = board[row][col];
        board[row][col] = '*';
        if (backtracking(board, word, row - 1, col, idx + 1) ||
            backtracking(board, word, row + 1, col, idx + 1) ||
            backtracking(board, word, row, col - 1, idx + 1) ||
            backtracking(board, word, row, col + 1, idx + 1)) {
                return true;
        }
        board[row][col] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string& word) {
        ROW = board.size();
        COL = board[0].size();
        LEN = word.length();

        for(int row = 0; row < ROW; ++row) {
            for(int col = 0; col < COL; ++col) {
                if(backtracking(board, word, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
