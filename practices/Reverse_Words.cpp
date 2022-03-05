#include <string>
#include <algorithm>

using namespace std;

class Solution {
// 思路：先反转串中的每个单词，然后反转整个串即可得到答案。
// 在处理空格符时，先移除串首的空格符，对于在两个单词间的空格
// 符，在碰到第一个空格符时先记录，如果下一位仍是空格符则删除
// 下一位的空格符，直到下一位是非空格符
private:
    // reverse part of the string in place
    void reverseWord(string& s, int i, int j) {
        while(i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }

    void removeLeadingSpaces(string& s) {
        while(*s.begin() == ' ') {
            s.erase(s.begin());
        }
    }

public:
    string reverseWords(string& s) {
        int i = 0, j;

        // Remove leading spaces
        removeLeadingSpaces(s);

        while(i < s.length()) {
            if(s[i] != ' ') {
                // isSpace = 0;
                j = i;
                while(j < s.length() && s[j] != ' ') {
                    ++j;
                }
                reverseWord(s, i, j - 1);
                i = j;
            }
            else {
                ++i;
                while(i < s.length() && s[i] == ' ') {
                    s.erase(s.begin() + i);
                }
            }
        }

        reverse(s.begin(), s.end());

        // Remove leading spaces after reversing the string
        removeLeadingSpaces(s);

        return s;
    }
};
