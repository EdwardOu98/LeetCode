#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // 当输入数组内元素个数小于3时直接返回空数组
        if(n < 3) {
            return {};
        }

        // 对输入数组进行排序以避免出现重复组合
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int sum; // 用于存储任意三个元素的和
        int lnum, rnum; // 用于暂存另外两个元素的值
        int l, r; // 用两个指针寻找两个和当前元素和为0的元素

        for(int i = 0; i < n; ++i) {
            // 因为结果要求三个元素的和为0，因此如果第一个数字
            // 已经大于0，则后面的数字无论怎么组合都不会小于0，
            // 可以直接退出循环
            if(nums[i] > 0) {
                break;
            }

            // 如果当前下标大于0且当前数字和前一位对数字相同，
            // 则说明可能会出现重复组合，所以直接跳过当前循环
            // 进入下一循环
            if(i && nums[i] == nums[i-1]) {
                continue;
            }

            // 用双指针法在下标i到数组末尾之间寻找其余两个元素
            l = i + 1, r = n - 1;
            while(l < r) {
                lnum = nums[l];
                rnum = nums[r];
                sum = nums[i] + lnum + rnum;
                if(sum == 0) {
                    // 如果当前的三个数和为0，则将三个数加入结果中
                    res.push_back({nums[i], lnum, rnum});
                    // 因为下标l和下标r对应的元素可能出现多个，需要用循环
                    // 跳过这些重复的元素
                    while((l < r) && (nums[l] == lnum)) {
                        ++l;
                    }
                    while((l < r) && (nums[r] == rnum)) {
                        --r;
                    }
                }
                else if (sum < 0) {
                    // 如果当前的和小于0，则说明需要增大左元素，又因为
                    // 左元素可能重复出现，故使用循环跳过重复元素
                    while((l < r) && (nums[l] == lnum)) {
                        ++l;
                    }
                }
                else {
                    // 如果当前的和大于0，则说明需要减小右元素，又因为
                    // 右元素可能重复出现，故使用循环跳过重复元素
                    while((l < r) && (nums[r] == rnum)) {
                        --r;
                    }
                }
            }
        }

        return res;
    }
};
