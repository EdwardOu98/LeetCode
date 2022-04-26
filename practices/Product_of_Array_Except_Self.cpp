#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, n = nums.size();
        vector<int> res(n);
        // Iterate through the array in the forward direction
        // and set the corresponding postion to prod, which is
        // the product of array elements up to the i-1th one.
        for(int i = 0; i < n; ++i) {
            res[i] = prod;
            prod *= nums[i];
        }
        
        prod = 1;
        // Iterate through the array again in the backward direction
        // and multiply the corresponding postion with prod
        for(int i = n - 1; i >= 0; --i) {
            res[i] *= prod;
            prod *= nums[i];
        }
        
        return res;
    }
};
