#include <vector>

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
            if(candidates[i] > target) {
                return;
            }
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        N = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);

        return res;
    }
};
