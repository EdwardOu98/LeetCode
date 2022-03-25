#include <vector>;

using namespace std;

class Solution {
private:
    // 思路1：用二分法在数组中搜索目标减去当前数的结果
    // 时间复杂度：O(nlogn)，外层循环执行n次，内层循环执行logn次
    vector<int> BinarySearch(vector<int>& numbers, int& target) {
        int l, r, i, n = numbers.size();

        for(i = 0; i < n; ++i) {
            int temp = target - numbers[i];
            l = i + 1;
            r = n - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(numbers[mid] == temp) {
                    return {i, mid};
                }
                else if(numbers[mid] < temp) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        return {};
    }

    // 思路2：双指针法
    // 时间复杂度：O(n)，循环最多执行n次
    vector<int> TwoPointers(vector<int>& numbers, int& target) {
        int l = 0, r = numbers.size() - 1, res;
        while(l < r) {
            res = numbers[l] + numbers[r];
            if(res == target) {
                return {l, r};
            }
            else if(res < target) {
                ++l;
            }
            else {
                --r;
            }
        }

        return {};
    }
public:
    vector<int> twoSum(vector<int>& numbers, int& target) {
        // return BinarySearch(numbers, target);
        return TwoPointers(numbers, target);
    }
};
