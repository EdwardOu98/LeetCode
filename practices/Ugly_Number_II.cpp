using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) {
            return n;
        }

        int n2 = 0, n3 = 0, n5 = 0;

        // dp[i](i > 0)代表第i个丑数，其中dp[0]为第一个丑数，其值为1
        int dp[n];
        dp[0] = 1;

        // 因为丑数到质因子只包含2、3、5，所以下一个丑数必定为现存丑数
        // 乘以2、3、5的结果中最小且尚不在结果数列中的那一个。如当前丑数
        // 为1，则下一个最小丑数且尚不在结果数列中的是2 * 1 = 2。此时需要
        // 将乘以2的丑数到下标向前移动一位来确保不会出现重复计算。对于3和5
        // 也是同理。
        for(int i = 1; i < n; ++i) {
            int a = 2 * dp[n2], b = 3 * dp[n3], c = 5 * dp[n5];
            dp[i] = min({a, b, c});
            if(dp[i] == a) {
                ++n2;
            }
            if(dp[i] == b) {
                ++n3;
            }
            if(dp[i] == c) {
                ++n5;
            }
        }

        return dp[n-1];
    }
};
