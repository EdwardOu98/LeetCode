using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        const int MOD = 1e9 + 7;
        // When n <= 2, the number of ways to climb the stairs
        // is the same as the number of stairs
        if(n <= 2) {
            return n;
        }
        // When n == 3, we have 4 ways to climb the stairs
        if(n == 3) {
            return 4;
        }

        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= n; ++i) {
            dp[i] = ((dp[i-1] + dp[i-2]) % MOD + dp[i-3]) % MOD;
        }

        return dp[n];
    }
};
