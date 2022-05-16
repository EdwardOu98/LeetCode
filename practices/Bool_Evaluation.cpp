#include <cstring>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<int>> memo;

    // DP with memoization (TLE)
    vector<int> dfs(string s) {
        vector<int> res;
        int n = s.length();

        for(int i = 0; i < n; ++i) {
            if(!isdigit(s[i])) {
                vector<int> res1, res2;
                char op = s[i];
                string str = s.substr(0, i);
                if(memo.count(str)) {
                    res1 = memo[str];
                }
                else {
                    res1 = dfs(str);
                }

                str = s.substr(i+1);
                if(memo.count(str)) {
                    res2 = memo[str];
                }
                else {
                    res2 = dfs(str);
                }

                for(int& a : res1) {
                    for(int& b : res2) {
                        if(op == '&') {
                            res.push_back(a & b);
                        }
                        else if(op == '|') {
                            res.push_back(a | b);
                        }
                        else {
                            res.push_back(a ^ b);
                        }
                    }
                }
            }
        }

        if(res.empty()) {
            res.push_back(stoi(s));
        }

        return memo[s] = res;
    }

    int eval(char op, int a, int b) {
        if(op == '&') {
            return a & b;
        }
        if(op == '|') {
            return a | b;
        }
        return a ^ b;
    }
public:
    int countEval(string s, int result) {
        int n = s.length();
        int dp[n][n][2]; // dp[i][j][x] - Number of 0 and 1's from index i to j
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                ++dp[i][i][0];
            }
            else if(s[i] == '1') {
                ++dp[i][i][1];
            }
        }

        for(int step = 2; step < n; step += 2) {
            for(int i = 0; i + step < n; i += 2) {
                int j = i + step;
                for(int k = i + 1; k < j; k += 2) {
                    int left0 = dp[i][k-1][0], left1 = dp[i][k-1][1];
                    int right0 = dp[k+1][j][0], right1 = dp[k+1][j][1];
                    dp[i][j][eval(s[k], 0, 0)] += left0 * right0;
                    dp[i][j][eval(s[k], 0, 1)] += left0 * right1;
                    dp[i][j][eval(s[k], 1, 0)] += left1 * right0;
                    dp[i][j][eval(s[k], 1, 1)] += left1 * right1;
                }
            }
        }

        return dp[0][n-1][result];
    }
};
