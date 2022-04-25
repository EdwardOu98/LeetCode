#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        
        int m = matrix.size(), n = matrix[0].size(); // Dimension of the matrix
        int maxLen = 0; // The edge length of the maximal square in the matrix
        int dp[m][n]; // dp[i][j] is the edge length of the square with matrix[i][j]
                      // as its bottom-right corner
        dp[0][0] = matrix[0][0] == '1' ? 1 : 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // If we are at the first row/column, dp[i][j] is 1 if matrix[i][j]
                // is 1. Otherwise, it's 0. 
                if(i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                }
                // In other cases, dp[i][j] is the minimum of dp[i-1][j], dp[i][j-1], and
                // dp[i-1][j-1] plus 1
                else if (matrix[i][j] == '1'){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        
        return maxLen * maxLen;
    }
};
