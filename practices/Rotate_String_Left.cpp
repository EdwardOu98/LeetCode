#include <algorithm>
#include <string>

using namespace std;

class Solution {
// 思路：反转前n位的字符，然后反转剩余字符，
// 最后将整个字符串反转即可得到答案
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
