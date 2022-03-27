#include <vector>
#include <unordered_map>

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i，n = nums.size();
        int counter = 0; // 记录当前0和1的个数的和
        unordered_map<int, int> mp; // 记录当前和出现的位置
        int maxLen = 0;

        mp[0] = -1;
        for(i = 0; i < n; ++i) {
            counter += (nums[i] == 1) ? 1 : -1;
            if(mp.count(counter)) {
                maxLen = max(maxLen, i - mp[counter]);
            }
            else {
                mp[counter] = i;
            }
        }

        return maxLen;
    }
};
