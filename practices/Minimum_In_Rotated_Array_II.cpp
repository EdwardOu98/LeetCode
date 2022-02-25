#include <vector>

using namespace std;

class Solution {
// 思路：通过二分法搜索。如果
// 中间值对应的数字比低值对应
// 的数字要大，说明从低值到中
// 间值之间的这一段数字位于旋
// 转前数组的尾部，需要将低值
// 设为中值+1。如果中值对应数
// 字和低值对应数字相等，则低
// 值+1。如果中值对应数字大于
// 高值对应数字，则说明从中值
// 到高值之间的这一段数字位于
// 旋转前数列的前部，需要将高
// 值设为中值。
public:
    int minArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high) {
            if(nums[low] < nums[high]) {
                return nums[low];
            }
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[low]) {
                low = mid + 1;
            }
            else if(nums[mid] == nums[low]) {
                ++low;
            }
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};
