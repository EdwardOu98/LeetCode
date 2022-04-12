#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 1; i < n; ++i) {
            if(nums[i] != nums[i-1]) {
                nums[i - count] = nums[i];
            }
            else {
                ++count;
            }
        }
        
        return n - count;
    }
};
