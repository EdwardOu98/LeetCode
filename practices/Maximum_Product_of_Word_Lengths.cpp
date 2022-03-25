#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
// 思路：把单词转变成二进制数，如果两个单词不包含相同字母，
// 则两个单词对应的二进制数的与结果必定为0
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int wordToNum[n];   // 用一个长度为n的整型数组来保存每个单词对应的二进制数
                            // 因为每个单词都只包含26个英文小写字母，所以使用32位
                            // 的整型就能存储对应的二进制数结果
        memset(wordToNum, 0, sizeof(wordToNum)); // 将数组初始化为0
        int res = 0;

        for(int i = 0; i < n; ++i) {
            for(char c : words[i]) {
                // 把每个字母的对应位设为1（如a对应从右数起第1位，b对应第二位等）
                wordToNum[i] |= 1 << (c - 'a');
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                // 两个不含有相同字母的单词对应的二进制数的与结果必定为0
                if(!(wordToNum[i] & wordToNum[j])) {
                    int temp = (int) words[i].length() * (int) words[j].length();
                    res = max(res, temp);
                }
            }
        }

        return res;
    }
};
