#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        
        for(int& num : nums) {
            target += num;
        }
        
        // If the sum of all elements in the input array
        // is less than x, it's not possible to reduce
        // x to 0. Thus, return -1
        if(target < 0) {
            return -1;
        }
        
        int j = 0, n = nums.size();
        int sum = 0;
        int maxLen = INT_MIN;
        
        // Find the largest window where the sum of all elements
        // in the window is equal to target
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            // If the sum of all elements in the current
            // window is greater than the target, we remove
            // 1 element each time from the left side of the
            // window until the sum is less than or equal to
            // target
            while(sum > target) {
                sum -= nums[j];
                ++j;
            }
            
            // If the current window's sum is equal to target,
            // calculate the window's length and compare it with
            // the previous maxLength
            if(sum == target) {
                maxLen = max(maxLen, i - j + 1);
            }
        }
        
        return maxLen == INT_MIN ? -1 : n - maxLen;
    }
};
