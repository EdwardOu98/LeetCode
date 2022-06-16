#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int expandFromCenter(string& s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        
        return r - l - 1;
    }
public:
    string longestPalindrome(string& s) {
        int len = s.size();
        
        if(len < 2) {
            return s;
        }
        
        int start = 0, end = 0;
        
        for(int i = 0; i < len; ++i) {
            int maxlen = max(expandFromCenter(s, i, i), expandFromCenter(s, i, i + 1));
            if(maxlen > end - start) {
                start = i - (maxlen - 1) / 2;
                end = i + maxlen / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};
