#include <vector>

using namespace std;

class Solution {
private:
    int N;
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int idx, int target) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        
        for(int i = idx; i < N; ++i) {
            if(i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            
            temp.push_back(nums[i]);
            dfs(res, temp, nums, i + 1, target - nums[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        N = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> res;
        
        dfs(res, temp, candidates, 0, target);
        
        return res;
    }
};
