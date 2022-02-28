using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numWays(int n) {
        if(n < 2) {
            return 1;
        }
        int dp[n + 1];
        dp[0] = dp[1] = 1;

        for(int i = 2; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i - 2]) % MOD;
        }

        return dp[n] % MOD;
    }
};
