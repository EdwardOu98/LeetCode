#include <string>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        int n = S.length();
        if(n <= 1) {
            return S;
        }
        string res;
        int count = 1;
        for(int i = 1; i < n; ++i) {
            if(S[i] != S[i-1]) {
                res += S[i-1] + to_string(count);
                count = 1;
            }
            else {
                ++count;
            }
        }

        res += S[n-1] + to_string(count);

        return res.length() < n ? res : S;
    }
};
