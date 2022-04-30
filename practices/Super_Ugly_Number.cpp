#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        int indices[m];
        memset(indices, 0, sizeof(indices));
        int res[n];
        res[0] = 1;
        
        for(int i = 1; i < n; ++i) {
            int temp = INT_MAX;
            // Calculate the i+1th ugly number
            for(int j = 0; j < m; ++j) {
                temp = min(temp, primes[j] * res[indices[j]]);
            }
            // Update the indices array
            for(int j = 0; j < m; ++j) {
                if(temp == primes[j] * res[indices[j]]) {
                    ++indices[j];
                }
            }
            res[i] = temp;
        }
        
        return res[n-1];
    }
};
