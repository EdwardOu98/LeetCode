#include <vector>

using namespace std;

class Solution {
// Magic Index: given a sorted array, find the index i where i == nums[i]
public:
    int findMagicIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ) {
            if(i == nums[i]) {
                return i;
            }
            i = max(i+1, nums[i]);
        }
        return -1;
    }
};
