#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        vector<int> res;
        nums.push_back(-1);
        nums.push_back(-1);
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(nums[i] != -1 && nums[i] != i + 1) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; ++i) {
            if(nums[i] == -1) {
                res.push_back(i+1);
            }
        }

        return res;
    }
};
