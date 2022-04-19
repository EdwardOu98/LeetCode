#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int res = 0, count;
        int currNum;
        int l, r;
        
        while(!uset.empty()) {
            currNum = *uset.begin();
            uset.erase(currNum);
            l = currNum - 1, r = currNum + 1;
            count = 1;
            while(uset.count(l)) {
                ++count;
                uset.erase(l--);
            }
            
            while(uset.count(r)) {
                ++count;
                uset.erase(r++);
            }
            
            res = max(res, count);
        }
        
        return res;
    }
};
