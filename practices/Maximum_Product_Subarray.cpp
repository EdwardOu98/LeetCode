#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return nums[0];
        }
        
        int maxProd = nums[0], minProd = nums[0], res = nums[0];
        
        for(int i = 1; i < n; ++i) {
            // If the current number is negative, we need to
            // swap maxProd and minProd because multiplying
            // a negative number will change the sign of the
            // number
            if(nums[i] < 0) {
                swap(maxProd, minProd);
            }
            
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            res = max(maxProd, res);
        }
        
        return res;
    }
};
