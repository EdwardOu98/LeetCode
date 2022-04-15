#include <vector>

using namespace std;

class Solution {
private:
    int linearSearch(vector<int>& nums) {
        int ret = 0;

        for(int& num : nums) {
            ret ^= num;
        }

        return ret;
    }

    // 思路：当一个数成对出现且还没出现单个数字的时候，其下标为偶数i，奇数i+1；
    // 在出现过单个数字之后，成对出现的数字就变为奇数i，偶数i+1。我们通过对偶数
    // 下标i和1进行异或操作即可得到其对应的另一个下标。如果两个下标对应的数相同，
    // 则说明单个数字仍未出现，应向右寻找；如果两个下标对应的数不同，则说明已经
    // 出现了单个数字，应向左寻找
    int binarySearch(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return nums[low];
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        // return linearSearch(nums);
        return binarySearch(nums);
    }
};
