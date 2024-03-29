#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        if(n == 1) {
            return 0;
        }

        int res = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(strs[j][i] < strs[j-1][i]) {
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};
