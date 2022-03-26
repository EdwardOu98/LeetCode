#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 如果输入数组为空直接返回0
        if(nums.empty()) {
            return 0;
        }

        int len = nums.size(); // 记录数组的长度   
        int l = 0, r = -1; // 记录当前子数组的左右边界
        int minLen = len + 1; // 初始结果长度为数组长度+1
        int sum = 0; // 记录当前子数组的和
        

        while(l < len) {
            // 如果当前子数组的右边界尚未到达数组末尾且当前子数组的和
            // 小于目标数，则将右边界右移一位并将新加入的数字记入和中
            if((r + 1 < len) && (sum < target)) {
                ++r;
                sum += nums[r];
            }
            else {
                // 如果当前的和已经大于目标数，则将子数组左边界上的数
                // 剔除，并从子数组和中减去该数
                sum -= nums[l];
                ++l;
            }

            if(sum >= target) {
                // 如果当前和大于等于目标数，则说明当前长度的子数组可能满足要求
                minLen = min(minLen, r - l + 1);
            }
        }

        // 如果整个数组的和都小于目标数，则说明不存在符合要求的子数组，返回0，否则返回最小长度
        return minLen == len + 1 ? 0 : minLen;
    }
};
