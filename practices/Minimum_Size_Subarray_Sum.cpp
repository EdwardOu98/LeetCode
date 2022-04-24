#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return target == nums[0] ? 1 : 0;
        }
        int l = 0, r = -1;  // Left and right boundary of the sliding
                            // window
        int minLen = n + 1; // Initial minLen is set to n + 1
        int sum = 0;
        
        while(l < n) {
            // If the right boundary of the window has not reached
            // the end of the array and the sum is smaller than target,
            // increment the window size and add the new element to
            // the sum
            if((r + 1 < n) && (sum < target)) {
                sum += nums[++r];
            }
            // If the right boundary has reached the end of the array and
            // the sum is greater than or equal to the target, subtract
            // the left-most element from the sum and decrement the window size.
            else {
                sum -= nums[l++];
            }
            
            if(sum >= target) {
                minLen = min(minLen, r - l + 1);
            }
        }
        
        return minLen == n + 1 ? 0 : minLen;
    }
};
