#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int M, N;
    
    bool dfs(vector<vector<char>>& board, int x, int y, string str) {
        // If s is empty, that means we have found every single
        // characters in s. Return true
        if(str.empty()) {
            return true;
        }
        
        // If x and y are out of bound or board[x][y] is not equal to
        // s[0], return false
        if(x < 0 || x >= M || y < 0 || y >= N || board[x][y] != str[0]) {
            return false;
        }
        
        char c = board[x][y];
        board[x][y] = '*';
        string s = str.substr(1);
        if(dfs(board, x + 1, y, s) || dfs(board, x - 1, y, s) || dfs(board, x, y + 1, s) || dfs(board, x, y - 1, s)) {
            board[x][y] = c;
            return true;
        }
        board[x][y] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size(), N = board[0].size();
        
        for(int x = 0; x < M; ++x) {
            for(int y = 0; y < N; ++y) {
                if(dfs(board, x, y, word)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
