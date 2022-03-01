#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }

        int sum = 0, maxSum = INT_MIN;

        for(int n : nums) {
            sum += n;
            maxSum = max(maxSum, sum);
            if(sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};
