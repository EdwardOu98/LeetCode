#include <algorithm>
#include <vector>

using namespace std;

class Solution {
// 思路：如果数组中存在重复的元素，则返回false；
// 如果数组中不存在0，则数组最大值和最小值的差必定为4；
// 如果数组中存在0，则数组最大值和最小值的差不能超过4
public:
    bool isStraight(vector<int>& nums) {
        int counter[14] = {0};
        int zeroCount = 0, maxVal = INT_MIN, minVal = INT_MAX;

        for(int num : nums) {
            if(num == 0) {
                ++zeroCount;
                continue;
            }
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
            if(++counter[num] > 1) {
                return false;
            }
        }
        return zeroCount ? ((maxVal - minVal) <= 4) : ((maxVal - minVal) == 4);
    }
};
