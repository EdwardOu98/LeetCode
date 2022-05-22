#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<vector<int>> hashmapSolution(vector<int>& nums, int target) {
        unordered_map<int, int> umap; // number - count
        vector<vector<int>> res;
        for(int& num : nums) {
            if(umap[target - num] > 0) {
                res.push_back({num, target - num});
                --umap[target - num];
            }
            else {
                ++umap[num];
            }
        }

        return res;
    }
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int sum;
        vector<vector<int>> res;

        while(i < j) {
            sum = nums[i] + nums[j];
            if(sum > target) {
                --j;
            }
            else if(sum < target) {
                ++i;
            }
            else {
                res.push_back({nums[i], nums[j]});
                ++i;
                --j;
            }
        }

        return res;
    }
};
