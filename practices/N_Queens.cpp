#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int N;
    bool isValid(vector<string>& temp, int x, int y) {
        int i, j;
        
        // check vertical directions 
        for(i = x - 1; i >= 0; --i) {
            if(temp[i][y] == 'Q') {
                return false;
            }
        }
        
        // Check diagonal directions
        i = x - 1, j = y - 1;
        while(i >= 0 && j >=0) {
            if(temp[i][j] == 'Q') {
                return false;
            }
            --i;
            --j;
        }
        
        i = x - 1, j = y + 1;
        while(i >= 0 && j < N) {
            if(temp[i][j] == 'Q') {
                return false;
            }
            --i;
            ++j;
        }
        
        return true;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& temp, int row) {
        if(row == N) {
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            if(isValid(temp, row, i)) {
                temp[row][i] = 'Q';
                dfs(res, temp, row + 1);
                temp[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        dfs(res, temp, 0);
        
        return res;
    }
};
