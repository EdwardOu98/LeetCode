#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {0};
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    ++rows[i][num];
                    ++cols[j][num];
                    ++boxes[(i / 3) * 3 + j / 3][num];
                    if(rows[i][num] > 1 || cols[j][num] > 1 || boxes[(i / 3) * 3 + j / 3][num] > 1) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
