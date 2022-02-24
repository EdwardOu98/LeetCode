#include <vector>

using namespace std;

class Solution {
// 思路：用一个数组来保存已经出现
// 过的数字。因为输入数组中的数字
// 都在0至n-1的范围内，所以可以用
// 数组的下标来代表出现的数字，而
// 下标对应的位置则用于保存该数字
// 出现的次数
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int elem[n];
        memset(elem, 0, sizeof(elem));

        for(int num : nums) {
            if(elem[num]) {
                return num;
            }
            ++elem[num];
        }

        return 0;
    }
};
