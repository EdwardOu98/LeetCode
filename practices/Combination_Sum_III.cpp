#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    
    void dfs(int k, int n, int num) {
        if(n == 0) {
            if(k == 0) {
                res.push_back(temp);
            }
            return;
        }
        
        for(int i = num; i <= 9 && i <= n; ++i) {
            temp.push_back(i);
            dfs(k - 1, n - i, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        
        return res;
    }
};
