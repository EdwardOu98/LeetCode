#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long dp[n];
        unordered_map<int, int> umap;
        for(int i = 0; i < n; ++i) {
            dp[i] = 1;
            umap[arr[i]] = i;
        }
        
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                // Use arr[j] as the left child
                if((arr[i] % arr[j]) == 0) {
                    // Calculate the right child
                    int right = arr[i] / arr[j];
                    // If the right child exist in the 
                    // input array, then the number of
                    // binary trees that can be formed
                    // with arr[i] being the root is
                    if(umap.count(right)) {
                        dp[i] = (dp[i] + dp[j] * dp[umap[right]]) % MOD;
                    }
                }
            }
        }
        
        long res = 0;
        
        for(int i = 0; i < n; ++i) {
            res = (res + dp[i]) % MOD;
        }
        
        return res;
    }
};
