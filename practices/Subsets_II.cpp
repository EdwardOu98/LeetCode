#include <vector>

using namespace std;

class Solution {
private:
    int targetLen, N;
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int idx) {
        if(temp.size() == targetLen) {
            res.push_back(temp);
        }
        
        for(int i = idx; i < N; ++i) {
            if(i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            
            temp.push_back(nums[i]);
            dfs(res, temp, nums, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        N = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        
        for(targetLen = 0; targetLen <= N; ++targetLen) {
            dfs(res, temp, nums, 0);
        }
        
        return res;
    }
};
