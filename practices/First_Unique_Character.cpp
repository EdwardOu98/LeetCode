#include <string>

using namespace std;

class Solution {
// 思路：先遍历一次整个字符串，
// 将每个字母出现的次数记录在
// 一个数组中。然后再遍历一次
// 字符串，返回第一个出现次数
// 为1的字母
public:
    char firstUniqChar(string s) {
        int chars[26] = {0};

        for(char c : s) {
            ++chars[c - 'a'];
        }

        for(char c : s) {
            if(chars[c - 'a'] == 1) {
                return c;
            }
        }

        return ' ';
    }
};
