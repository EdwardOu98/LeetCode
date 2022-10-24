#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(umap.count(nums[i]) && i - umap[nums[i]] <= k) {
                return true;
            }
            umap[nums[i]] = i;
        }
        
        return false;
    }
};
