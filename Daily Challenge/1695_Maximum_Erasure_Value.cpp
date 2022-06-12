#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> uset;
        int n = nums.size();
        int i = 0, j = 0;
        int maxSum = 0, sum = 0;
        
        while(i < n) {
            // If the current number in the right boundary
            // has not appeared before, add it to the window
            // and update the maximum sum
            if(!uset.count(nums[i])) {
                uset.insert(nums[i]);
                sum += nums[i];
                maxSum = max(maxSum, sum);
                ++i;
            }
            // Otherwise, we remove the left boundary element
            // from the window until the element on the right
            // boundary isn't in the window
            else {
                uset.erase(nums[j]);
                sum -= nums[j];
                ++j;
            }
        }
        
        return maxSum;
    }
};
