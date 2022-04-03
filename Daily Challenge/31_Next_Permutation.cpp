#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // Iterate through the array from the end yo find
        // the first pair of elements that satisfy the condition
        // nums[i+1] > nums[i]
        while(i >= 0 && nums[i+1] <= nums[i]) {
            --i;
        }
        
        // If we are able to find such pair (i >= 0), we iterate through
        // the array from the right again to find the first element that
        // is just larger than nums[i] and swap that number with nums[i]
        if(i >= 0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        
        // After swapping the two elements (or no pair was found in the
        // first iteration), we simply reverse the string starting from
        // the ith element to find the next permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};
