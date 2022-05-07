#include <cstring>
#include <iostream>

using namespace std;

static const int MOD = 998244353;

/* Problem: 
 * A wants to decorate his desk. There are m slots to place the
 * decorations. A wants to arrange the decorations in a way that
 * the price of decoration on the right side is a multiple of 
 * that on the left (let's say the price for the decorations are
 * a[1], a[2], ..., a[m], then for 1 <= i <= j <= m, a[j] is a 
 * multiple of a[i]). A has a budget of n dollars. How many ways
 * are there for A to purchase the decorations? 
 */

int main(void) {
    int n, m; // n - Budget to purchase decorations
              // m - Number of decorations
    cin >> n >> m;

    // If there's only one kind of decorations, then there're n ways to purchase
    // the decorations
    if(m == 1) {
        cout << n << endl;
        return 0;
    }

    int dp[n+1][m]; // dp[i][j] means for a budget of a budget of i, how many ways
                    // there are to purchase j decorations 
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; ++i) {
        // Given a budget of n, to purchase 1 deecoration with price i, ways to 
        // purchase the decorations are n / i
        dp[i][1] = n / i;
    }

    for(int j = 2; j < m; ++j) {
        // We don't need to consider decorations with price greater than n / 2 because
        // any multiplier larger than 1 will cause the final price exceed the budget
        for(int i = 1; i <= n / 2; ++i) {
            for(int k = i; k <= n; k += i) {
                dp[i][j] += k > n / 2 ? 1 : dp[k][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    int res = n - n / 2;
    for(int i = 1; i <= n / 2; ++i) {
        res = (res + dp[i][m-1]) % MOD;
    }

    cout << res << endl;

    return 0;
}
