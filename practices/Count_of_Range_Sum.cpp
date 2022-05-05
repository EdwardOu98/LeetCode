#include <vector>

using namespace std;

class Solution {
private:
    int mergeSortAndCount(vector<long>& prefixSum, int low, int high, int& lower, int& upper) {
        // If the current part contains 0 elements, return 0
        if(low > high) {
            return 0;
        }
        // If the current part contains only 1 element, check whether it falls in the range
        // of [lower, upper]
        if(low == high) {
            return ((prefixSum[low] >= lower) && (prefixSum[low] <= upper)) ? 1 : 0;
        }
        vector<long> temp(high - low + 1, 0);
        int mid = low + (high - low) / 2;
        int res = mergeSortAndCount(prefixSum, low, mid, lower, upper) + 
                  mergeSortAndCount(prefixSum, mid+1, high, lower, upper);
        for(int i = low, j = mid+1, k = mid+1; i <= mid; ++i) {
            // Count the sums in the valid range
            while(j <= high && prefixSum[j] - prefixSum[i] < lower) {
                ++j;
            }
            while(k <= high && prefixSum[k] - prefixSum[i] <= upper) {
                ++k;
            }
            res += k - j;
        }
        
        // merge the two sorted region
        for(int i = low, k = low, j = mid+1; k <= high; ++k) {
            temp[k - low] = (i <= mid) && (j > high || prefixSum[i] < prefixSum[j]) ? 
                            prefixSum[i++] : prefixSum[j++];
        }
        
        for(int i = low; i <= high; ++i) {
            prefixSum[i] = temp[i - low];
        }
        
        return res;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefixSum(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        
        return mergeSortAndCount(prefixSum, 1, n, lower, upper);
    }
};
