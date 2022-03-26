#include <vector>

using namespace std;

class Solution {
private:
    // 暴力求解TLE
    int bruteForce(vector<int>& nums, int& k) {
        int counter = 0, n = nums.size(), i, j;
        long product;

        for(i = 0; i < n; ++i) {
            product = 1;
            for(j = i; j < n; ++j) {
                product *= nums[j];
                if(product >= k) {
                    break;
                }
                ++counter;
            }
        }

        return counter;
    }

    int slidingWindow(vector<int>& nums, int& k) {
        int n = nums.size(); // 数组大小
        int l = 0, r = 0; // 滑动窗口的左右边界
        int counter = 0; // 记录乘积小于k的子数组的个数
        long product = 1; // 用long型避免溢出

        while(r < n) {
            product *= nums[r++];
            while(l < r && product >= k) {
                product /= nums[l++];
            }
            counter += r - l;
        }

        return counter;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int& k) {
        return slidingWindow(nums, k);
    }
};
