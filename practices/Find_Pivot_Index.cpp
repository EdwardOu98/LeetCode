#include <vector>

using namespace std;

class Solution {
private:
    // 思路1: 前缀和
    // 时间复杂度O(n)，空间复杂度O(n)
    int PrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0); 
        // 计算前缀和
        for(int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        // 以数组中的第i个数为轴，如果轴左侧的前缀和(即prefixSum[i])等于轴右侧所有
        // 数字的和(即prefixSum[n] - prefixSum[i] - nums[i]，最后要减去nums[i]
        // 因为nums[i]作为轴不进入和的运算)相等，则返回i
        for(int i = 0; i < n; ++i) {
            if(prefixSum[i] == (prefixSum[n] - prefixSum[i] - nums[i])) {
                return i;
            }
        }

        return -1;
    }
    // 思路2: 空间优化
    // 时间复杂度O(n)，空间复杂度O(1)
    int OptimizedSpace(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; // 记录从第i+1位开始到最后一位的和
        int curr = 0; // 记录当前数轴左侧的数字的和

        // 求数组中所有元素的和
        for(int& num : nums) {
            sum += num;
        }

        // 从0开始，每次将数轴右移一位，检查数轴两侧的和是否相等
        // 如果相等，则返回当前数轴对应的下标
        for(int i = 0; i < n; ++i) {
            sum -= nums[i];
            if(curr == sum) {
                return i;
            }
            curr += nums[i];
        }

        return -1;
    }
public:
    int pivotIndex(vector<int>& nums) {
        return OptimizedSpace(nums);
    }
};
