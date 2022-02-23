#include <string>;

using namespace std;

class Solution {
// 思路：从前往后扫描整个字符串，在遇到
// 空格符时，在当前位置插入“%20”， 将i
// 后移两位之后，通过erase函数将空格符
// 抹去然后更新字符串长度
public:
    string replaceSpace(string s) {
        int n = s.length();

        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') {
                s.insert(i, "%20");
                i += 2;
                s.erase(i + 1, 1);
                n += 2;
            }
        }

        return s;
    }
};
