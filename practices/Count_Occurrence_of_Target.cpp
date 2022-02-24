#include <vector>

using namespace std;

class Solution {
// 思路：用二分搜索分别找到目标
// 出现的第一个下标和最后一个下标，
// 如果找不到（搜索函数返回值为-1），
// 主函数返回0；如果找到了，则用
// 最后一个下标的值减去第一个下标的
// 值然后加1以得到元素的总个数
private:
    int N;
    int findFirstPosition(vector<int>& nums, int target) {
        int low = 0, high = N - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                if(((mid == 0) && (nums[mid] == target)) ||
                    ((nums[mid] == target) && (nums[mid - 1] != target))) {
                    return mid;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }

    int findLastPosition(vector<int>& nums, int target) {
        int low = 0, high = N - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                if(((mid == N - 1) && (nums[mid] == target)) ||
                    ((nums[mid] == target) && (nums[mid + 1] != target))) {
                    return mid;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        N = nums.size();
        
        int firstPos = findFirstPosition(nums, target);
        int lastPos = findLastPosition(nums, target);

        if(firstPos == -1 && lastPos == -1) {
            return 0;
        }

        return lastPos - firstPos + 1;
    }
};
