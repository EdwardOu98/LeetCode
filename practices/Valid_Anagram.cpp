#include <string>
#include <algorithm>

using namespace std;

class Solution {
private: 
    bool counter(string& s, string& t) {
        int n = s.length();
        if(t.length() != n) {
            return false;
        }
        int charCount[26] = {0};
        
        for(int i = 0; i < n; ++i) {
            ++charCount[s[i] - 'a'];
            --charCount[t[i] - 'a'];
        }
        
        for(int i = 0; i < 26; ++i) {
            if(charCount[i] != 0) {
                return false;
            }
        }
        
        return true;
    }

    bool sorting(string& s, string& t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
public:
    bool isAnagram(string& s, string& t) {
        // 如果s和t长度不同或s和t的字母出现次数和位置都完全相同
        // 则说明s和t不是变位词
        if((s.size() != t.size()) || (s == t)) {
            return false;
        }
        // return counter(s, t);
        return sorting(s, t);
    }
};
