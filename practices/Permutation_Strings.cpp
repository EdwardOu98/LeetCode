#include <cstring>
#include <vector>
#include <string>

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
        bool used[n];
        memset(used, false, sizeof(used));
        dfs(S, used);

        return res;
    }
};
