#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1]; // Use the last row of
                                          // the triangle as the
                                          // dp array

        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};
