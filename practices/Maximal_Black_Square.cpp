#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        // dp[i][j][0] is the number of 0's on the left of [i, j] (inclusive)
        // dp[i][j][1] is the number of 0's on the top of [i, j] (inclusive)
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
        vector<int> res(3, 0);

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // If the current grid is 0
                if(matrix[i-1][j-1] == 0) {
                    dp[i][j][0] += dp[i][j-1][0] + 1;
                    dp[i][j][1] += dp[i-1][j][1] + 1;
                    // The edge length of the square with [i, j] as its bottom right corner
                    int len = min(dp[i][j][0], dp[i][j][1]);
                    while(len > 0) {
                        // If we are able to form a square
                        if(dp[i-len+1][j][0] >= len && dp[i][j-len+1][1] >= len) {
                            // If the new square is greater than the previous one, update the
                            // square information
                            if(len > res[2]) {
                                res = {i-len, j-len, len};
                            }
                            break;
                        }
                        // If we can't form a square, try to reduce the length of the edges
                        else {
                            --len;
                        }
                    }
                }   
            }
        }

        // If the longest edge of the largest square has length 0, return an empty string
        if(res[2] == 0) {
            return {};
        }
        return res;
    }
};
