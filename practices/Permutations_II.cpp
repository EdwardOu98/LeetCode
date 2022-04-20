#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    int N;

    void dfs(vector<int>& nums, bool used[]) {
        if(temp.size() == N) {
            res.push_back(temp);
        }

        for(int i = 0; i < N; ++i) {
            if(!used[i]) {
                if(i && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                }

                used[i] = true;
                temp.push_back(nums[i]);
                dfs(nums, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        N = nums.size();
        bool used[N];
        memset(used, false, sizeof(used));

        dfs(nums, used);

        return res;
    }
};
