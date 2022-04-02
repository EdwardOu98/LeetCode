#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private: 
    bool counter(string& s, string& t) {
        vector<int> schar(26, 0), tchar(26, 0);
        for(char& c : s) {
            ++schar[c - 'a'];
        }

        for(char& c : t) {
            ++tchar[c - 'a'];
        }

        return schar == tchar;
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
