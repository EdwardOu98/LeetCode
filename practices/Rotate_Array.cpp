#include <vector>

using namespace std;

class Solution {
private:
    void reverseArray(vector<int>& nums, int l, int r) {
        int temp;
        while(l < r) {
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            ++l;
            --r;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0) {
            return;
        }
        
        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
};
