#include <vector>

using namespace std;

class Solution {
private:
    int count = 0;

    // 用归并排序计算逆序对的数量
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int n = right - left + 1;
        int temp[n];
        

        int i = left;
        int j = mid + 1;
        int t = 0;

        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                temp[t] = nums[i];
                ++t;
                ++i;
            }
            else {
                // 由于合并时从left到mid之间的段都是有序的，因此存在mid-i+1个逆序对
                count += mid - i + 1;
                temp[t] = nums[j];
                ++t;
                ++j;
            }
        }

        while(i <= mid) {
            temp[t] = nums[i];
            ++t;
            ++i;
        }

        while(j <= right) {
            temp[t] = nums[j];
            ++t;
            ++j;
        }

        for(int k = 0; k < n; ++k) {
            nums[left + k] = temp[k];
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
