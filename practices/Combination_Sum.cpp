#include <vector>

using namespace std;

class Solution {
private:
    int N; // size of candidate array
    void backtracking(vector<int>& candidates, int target, int index, vector<int>& tmp, vector<vector<int>>& res) {
        if(target < 0) {
            return;
        }
        
        if(target == 0) {
            res.push_back(tmp);
            return;
        }
        
        for(int i = index; i < N; ++i) {
            tmp.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i, tmp, res);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        N = candidates.size();
        if(N == 0) {
            return {};
        }
        
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(candidates, target, 0, tmp, res);
        
        return res;
    }
};
