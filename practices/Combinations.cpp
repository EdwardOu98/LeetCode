#include <vector>

using namespace std;

class Solution {
private:
    int n, k;
    vector<int> temp;
    vector<vector<int>> res;

    void dfs(int idx) {
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i <= n; ++i) {
            temp.push_back(i);
            dfs(i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int _n, int _k) {
        n = _n;
        k = _k;

        dfs(1);

        return res;
    }
};
