#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int N;
    int res = 0;
    vector<string> board;

    bool isValid(int x, int y) {
        int i, j;
        
        // check vertical directions 
        for(i = x - 1; i >= 0; --i) {
            if(board[i][y] == 'Q') {
                return false;
            }
        }
        
        // Check diagonal directions
        i = x - 1, j = y - 1;
        while(i >= 0 && j >=0) {
            if(board[i][j] == 'Q') {
                return false;
            }
            --i;
            --j;
        }
        
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
        if(row == N) {
            ++res;
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            if(isValid(row, i)) {
                board[row][i] = 'Q';
                dfs(row + 1);
                board[row][i] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        N = n;
        
        board = vector<string>(n, string(n, '.'));
        
        dfs(0);
        
        return res;
    }
};
