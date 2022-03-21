#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // 对于有n个骰子的情况，其能掷出的结果的和有5 * n + 1种
        vector<double> res(5 * n + 1);

        // 总共有6的n次方种组合方式
        double totalCombinations = pow(6, n);

        // dp[i][j]的含义是有i个骰子时能掷出结果为j的组合方式的数量
        int dp[n+1][6 * n + 1];

        memset(dp, 0, sizeof(dp));

        // 当只有一个骰子时，每个结果只有一种组合方式
        for(int i = 1; i <= 6; ++i) {
            dp[1][i] = 1;
        }

        // 第一层循环：遍历从1个骰子到n个骰子的情况
        for(int i = 1; i <= n; ++i) {
            // 第二层循环：遍历有i个骰子的情况下所有可能的组合结果
            for(int j = i; j <= 6 * i; ++j) {
                // 第三层循环：第i个骰子(即最新扔出的骰子)的点数
                for(int k = 1; k <= 6; ++k) {
                    // 因为先前扔出i-1个骰子得到的结果的和不可能小于当前
                    // 扔出的一个骰子的点数，所以当j小于当前掷出的点数时
                    // 忽略不计。
                    dp[i][j] += ((j >= k) ? dp[i-1][j-k] : 0);
                    if(i == n) {
                        res[j - i] = dp[i][j] / totalCombinations;
                    }
                }
            }
        }

        return res;
    }
};
