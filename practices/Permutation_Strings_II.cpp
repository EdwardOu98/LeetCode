#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;
    string temp;
    int n;

    void dfs(string& s, bool used[]) {
        if(temp.size() == n) {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < n; ++i) {
            if(!used[i]) {
                if(i && s[i] == s[i-1] && !used[i-1]) {
                    continue;
                }

                used[i] = true;
                temp.push_back(s[i]);
                dfs(s, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<string> permutation(string S) {
        n = S.length();
        sort(S.begin(), S.end());
        bool used[n];
        memset(used, false, sizeof(used));

        dfs(S, used);
        return res;
    }
};
