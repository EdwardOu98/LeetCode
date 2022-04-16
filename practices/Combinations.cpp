#include <vector>

using namespace std;

class Solution {
private:
    int n, k;
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, int idx) {
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }
        
        for(int i = idx; i <= n; ++i) {
            temp.push_back(i);
            dfs(res, temp, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int _n, int _k) {
        n = _n;
        k = _k;
        vector<vector<int>> res;
        vector<int> temp;
        
        dfs(res, temp, 1);
        
        return res;
    }
};
