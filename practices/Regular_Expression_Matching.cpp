#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[i][j]的含义为s中从串首开始长度为i的子串和
        // p中从串首开始长度为j的子串的匹配情况

        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        // 分两种情况讨论
        // 第一种：p当前位置上的字符为'*'，则先检查dp[i][j-2]是否为true(即p中到'*'的前一个字符之前的子串
        // 和s中长度为i的子串是否相同)。如果为true，则可直接将dp[i][j]设为真(因为'*'的前一个字符可以出现
        // 包括0在内的任意次数)。如果为false，则检查dp[i-1][j]是否为真(即p中到'*'的前一个字符为止的子串
        // 和p中长度为i-1的子串是否相同)。如果为true，则继续检查p中'*'前的字符和s中下标为i-1的字符是否相同
        // 或*的前一个字符是否为'.'。如果符合任意一种情况，则dp[i][j]为真，否则为false。

        // 第二种：p当前位置上的字符不为'*'。此时需先检查p中长度为j-1的子串和s中长度为i-1的子串是否相同，
        // 如果不同则dp[i][j]也为false。如果相同则进一步检查p和s在当前位置上的字符是否相同或p当前位置上
        // 的字符是否为'.'。如果相同或为'.'则dp[i][j]为true，否则为false。
        for(int i = 0; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && ((s[i-1] == p[j-2]) || (p[j-2] == '.')));
                }
                else {
                    dp[i][j] = i && dp[i-1][j-1] && ((s[i-1] == p[j-1]) || (p[j-1] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};
