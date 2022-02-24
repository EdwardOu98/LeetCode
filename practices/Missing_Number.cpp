#include <vector>

using namespace std;

class Solution {
// 思路：用二分法找出缺少的数字所在的下标。
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] != mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return ((low == n - 1) && (nums[low] == low)) ? low + 1 : low;
    }
};
