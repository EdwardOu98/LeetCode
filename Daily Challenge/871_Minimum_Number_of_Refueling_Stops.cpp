#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) {
            return 0;
        }
        
        if(stations.empty()) {
            return startFuel < target ? -1 : 0;
        }
        
        int n = stations.size();
        long dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = startFuel;
        
        for(int i = 0; i < n; ++i) {
            for(int t = i; t >= 0; --t) {
                if(dp[t] >= stations[i][0]) {
                    dp[t+1] = max(dp[t+1], dp[t] + stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i <= n; ++i) {
            if(dp[i] >= target) {
                return i;
            }
        }
        
        return -1;
    }
};
