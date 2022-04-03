#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int dictionary[26]; // 用于保存外星语言中字母的大小顺序

    bool compare(string& a, string& b) {
        int lenA = a.length(), lenB = b.length();
        int len = min(lenA, lenB); // 循环长度取a和b长度的最小值
        for(int i = 0; i < len; ++i) {
            // 找到a和b当前字母在外星语中的先后次序
            int orderA = dictionary[a[i] - 'a'];
            int orderB = dictionary[b[i] - 'a'];
            // 如果a的次序比b大，返回false
            if(orderA > orderB) {
                return false;
            }
            // 如果a的次序比b小，返回true
            else if(orderA < orderB) {
                return true;
            }
            // 如果两者相等，则继续循环
        }

        // 如果遍历完其中一个词后仍未分出大小，则检查a和b的长度。
        return lenA <= lenB;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = words.size(), m = order.length();
        for(int i = 0; i < m; ++i) {
            dictionary[order[i] - 'a'] = i;
        }

        for(int i = 1; i < n; ++i) {
            if(!compare(words[i-1], words[i])) {
                return false;
            }
        }

        return true;
    }
};
