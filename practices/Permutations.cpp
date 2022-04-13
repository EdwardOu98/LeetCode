#include <vector>

using namespace std;

class Solution {
private:
    int N;
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, vector<bool>& used) {
        if(temp.size() == N) {
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            if(!used[i]) {
                used[i] = true;
                temp.push_back(nums[i]);
                dfs(res, temp, nums, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        N = nums.size();
        vector<bool> used(N, false);
        
        dfs(res, temp, nums, used);
        
        
        return res;
    }
};
