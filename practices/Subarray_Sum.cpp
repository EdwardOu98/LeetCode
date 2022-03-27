#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // 滑动窗口：只能用于数组中无负数的情况
    int slidingWindow(vector<int>& nums, int& k) {
        int n = nums.size();
        int sum = 0; // 记录每个子数组的和
        int l = 0, r = -1;
        int count = 0; // 记录和为k的子数组的个数

        while(l < n) {
            if((r + 1 < n) && (sum < k)) {
                sum += nums[++r];
            }
            else {
                sum -= nums[l++];
            }

            cout << sum << " ";

            if(sum == k) {
                ++count;
            }
        }

        return count;
    }

    // 前缀和+Hash Table加速运算
    int prefixSum(vector<int>& nums, int& k) {
        unordered_map<int, int> mp; // 每个和的出现次数{和 ： 次数}
        int n = nums.size();
        int prefix = 0;
        int count = 0;
        mp[0] = 1; // 将mp[0]设为1可以保证如果第一个数就是k的话也能被计入
        for(int& num : nums) {
            prefix += num;
            if(mp.count(prefix - k)) {
                count += mp[prefix - k];
            }
            ++mp[prefix];
        }

        return count;
    }
public:
    int subarraySum(vector<int>& nums, int& k) {
        return prefixSum(nums, k);
    }
};
