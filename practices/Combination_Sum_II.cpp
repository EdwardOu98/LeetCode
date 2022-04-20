#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    int N;

    void dfs(vector<int>& candidates, int target, int idx) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i < N; ++i) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(candidates[i] > target) {
                return;
            }
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        N = candidates.size();

        dfs(candidates, target, 0);

        return res;
    }
};
