#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // Given a division a/b/c/d, to maximize the result, 
        // we can minimize the denominator. That it, we need
        // to try to minimize b/c/d. There are two ways to 
        // arrange the parentheses: (b/c)/d and b/(c/d). If we
        // let b = 1, we will have 1 / (c * d) and d / c. It's
        // obvious that 1 / (c * d) < d / c for d > 1. Thus, we
        // should choose (b/c)/d, or b/c/d as the parentheses are
        // unnecessary. And the result should be a/(b/c/d). This
        // theory can also be applied to expressions with more
        // operands. 
        int n = nums.size();
        string res = to_string(nums[0]);
        if(n == 1) {
            return res;
        }
        if(n == 2) {
            return res + "/" + to_string(nums[1]);
        }
        res += "/(";
        
        for(int i = 1; i < n; ++i) {
            res += to_string(nums[i]);
            if(i != n-1) {
                res += "/";
            }
        }
        res += ")";
        
        return res;
    }
};
