#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int N;
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, bool used[]) {
        if(temp.size() == N) {
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            if(!used[i]) {
                if(i && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                }
                
                used[i] = true;
                temp.push_back(nums[i]);
                dfs(res, temp, nums, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        bool used[N];
        memset(used, false, sizeof(used));
        
        sort(nums.begin(), nums.end());
        
        dfs(res, temp, nums, used);
        
        return res;
    }
};
