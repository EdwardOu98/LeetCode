#include <vector>

using namespace std;

class Solution {
private:
    int N;
    int targetLen;
    void backtracking(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int index) {
        
        
        if(tmp.size() == targetLen) {
            res.push_back(tmp);
            return;
        }
        
        for(int i = index; i < N; ++i) {
            tmp.push_back(nums[i]);
            backtracking(nums, tmp, res, i + 1);
            tmp.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        
        for(targetLen = 1; targetLen <= N; ++targetLen) {
            backtracking(nums, tmp, res, 0);
        }
        
        return res;
    }
};
