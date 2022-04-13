#include <vector>

using namespace std;

class Solution {
private:
    struct index {
        int x, y;
        index(int row, int col) {
            x = row;
            y = col;
        }
    };
    
    void dfs(vector<vector<char>>& board, vector<index>& indices, int idx, bool& succ) {
        if(succ) {
            return;
        }
        
        if(idx == indices.size()) {
            succ = true;
            return;
        }
        index emptyPos = indices[idx];
        for(int i = 1; i < 10; ++i) {
            if(!succ && isValid(board, emptyPos, i)) {
                board[emptyPos.x][emptyPos.y] = i + '0';
                dfs(board, indices, idx + 1, succ);
                if(succ) {
                    return;
                }
                board[emptyPos.x][emptyPos.y] = '.';
            }
        }
    }
    
    bool isValid(vector<vector<char>>& board, index& idx, int num) {
        int i, j;
        char cnum = num + '0';
        for(i = 0; i < 9; ++i) {
            if(board[i][idx.y] == cnum) {
                return false;
            }
        }
        
        for(j = 0; j < 9; ++j) {
            if(board[idx.x][j] == cnum) {
                return false;
            }
        }
        
        int px = idx.x - idx.x % 3, py = idx.y - idx.y % 3;
        for(i = px; i < px + 3; ++i) {
            for(j = py; j < py + 3; ++j) {
                if(board[i][j] == cnum) {
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<index> indices;
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    indices.push_back(index(i, j));
                }
            }
        }
        
        bool succ = false;
        
        dfs(board, indices, 0, succ);
    }
};
