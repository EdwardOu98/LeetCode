#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<int>& res, int& num, int n) {
        if(n == 0) {
            res.push_back(num);
            return;
        }
        
        dfs(res, num, n - 1);
        num ^= 1 << (n - 1);
        dfs(res, num, n - 1);
    }
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int num = 0;
        
        dfs(res, num, n);
        
        return res;
    }
};
