#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(vector<string>& res, string& s, int pos, const int& n) {
        if(pos == n) {
            res.push_back(s);
            return;
        }

        for(int i = pos; i < n; ++i) {
            bool flag = true;

            // 检查从pos到i是否有与i相同的字母，如果有则去重
            for(int j = pos; j < i; ++j) {
                if(s[j] == s[i]) {
                    flag = false;
                }
            }

            if(flag) {
                swap(s[pos], s[i]);
                dfs(res, s, pos + 1, n);
                swap(s[pos], s[i]);
            }
        }
    }
public:
    vector<string> permutation(string& s) {
        vector<string> res;

        dfs(res, s, 0, s.length());

        return res;
    }
};
