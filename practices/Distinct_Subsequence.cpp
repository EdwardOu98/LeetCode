#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        if(m == n && s == t) {
            return 1;
        }
        
        unsigned long dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        // If t[i-1] != s[j-1], the distinct subsequence will not include s[j-1], and
        // the total number of distinct subsequence will be those from s[0...j-2], which
        // corresponds to dp[i][j-1];
        // If t[i-1] == s[j-1], the distinct sequence will include s[j-1], and the total
        // number of distinct subsequence will be those from s[0...j-1], which corresponds
        // to dp[i-1][j-1] + dp[i][j-1];
        // An empty string will have exactly one subsequence in any string
        // Non-empty string will have zero subsequence in any empty string
        int i, j;
        for(j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        
        for(i = 1; i <= m; ++i) {
            for(j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        
        return dp[m][n];
    }
};
