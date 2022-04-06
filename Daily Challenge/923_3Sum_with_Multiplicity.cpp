#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // Use long type to avoid overflow
        long counter[101] = {0};
        int unique = 0; // number of unique elements
        
        // Record number of occurences of each number
        for(int& num : arr) {
            ++counter[num];
            if(counter[num] == 1) {
                ++unique;
            }
        }
        
        // Record the unique keys
        int keys[unique];
        memset(keys, 0, sizeof(keys));
        int i, j = 0, k, t, x, y, z;
        for(i = 0; i <= 100; ++i) {
            if(counter[i]) {
                keys[j++] = i;
            }
        }
        
        long res = 0;
        for(i = 0; i < unique; ++i) {
            x = keys[i];
            t = target - x;
            j = i, k = unique - 1;
            while(j <= k) {
                y = keys[j];
                z = keys[k];
                // If sum is smaller than target, increment j
                if(y + z < t) {
                    ++j;
                }
                // If sum is greeater than target, decrement k
                else if(y + z > t) {
                    --k;
                }
                // If sum is equal to target, calculate the contribution
                // of each number
                else {
                    // If all three numbers are different, then we have
                    // counter[x] * counter[y] * counter[z] kinds of 
                    // combinations that satisfies the condition
                    if(i < j && j < k) {
                        res += counter[x] * counter[y] * counter[z];
                    }
                    // If x is equal to y and z is different, then we have
                    // (counter[x] * (counter[x] - 1)) / 2 * counter[z] kinds
                    // of combinations that satisfies the condition. We need to
                    // divide the first part by 2 because some combinations are
                    // counted twice
                    else if(i == j && j < k) {
                        res += (counter[x] * (counter[x] - 1)) / 2 * counter[z];
                    }
                    // If y is equal to z and x is different, then we have
                    // counter[x] * (counter[y] * (counter[y] - 1)) / 2 kinds
                    // of combinations that satisfies the condition. We need to
                    // divide the second part by 2 because some combinations are
                    // counted twice
                    else if(i < j && j == k) {
                        res += counter[x] * (counter[y] * (counter[y] - 1)) / 2;
                    }
                    // If all three elements are the same, then we have
                    // (counter[x] * (counter[x] - 1) * (counter[x] - 2)) / 6
                    // kinds of combination that safisfies the condition
                    else {
                        res += (counter[x] * (counter[x] - 1) * (counter[x] - 2)) / 6;
                    }
                    
                    res %= MOD;
                    ++j;
                    --k;
                }
            }
        }
        
        return res;
    }
};
