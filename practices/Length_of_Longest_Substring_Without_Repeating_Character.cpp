#inlcude <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) {
            return 0;
        }

        int maxLen = 0;

        for(int i = 0; i < n; ++i) {
            int used[256] = {0};
            int len = 0;
            for(int j = i; j < n; ++j) {
                if(used[s[j]]) {
                    break;
                }
                ++used[s[j]];
                ++len;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
