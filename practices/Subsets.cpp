#include <vector>

using namespace std;

class Solution {
private:
    int targetLen, N;
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& nums, int idx) {
        if(temp.size() == targetLen) {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i < N; ++i) {
            temp.push_back(nums[i]);
            dfs(nums, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        for(targetLen = 0; targetLen <= N; ++targetLen) {
            dfs(nums, 0);
        }

        return res;
    }
};
