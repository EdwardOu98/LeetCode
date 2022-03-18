#include <cctype>
#include <string> 

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // 如果输入串为空，直接返回false
        if(s.empty()) {
            return false;
        }

        // 去掉先导空格
        // while(!s.empty() && s[0] == ' ') {
        //     s.erase(s.begin());
        // }

        // 找到第一个不为空格的字符
        int idx = s.find_first_not_of(' ');
        // 如果idx的值为-1，则说明整个字符串都是空格，直接返回false
        if(idx == -1) {
            return false;
        }

        // 去掉后续空格
        // while(!s.empty() && s[s.length() - 1] == ' ') {
        //     s.erase(s.end() - 1);
        // }

        int endIdx = s.find_last_not_of(' ');

        bool numFlag = false;   // 记录是否出现数字
        bool dotFlag = false;   // 记录是否出现小数点
        bool eFlag = false;     // 记录是否出现e或E

        for(int i = idx; i <= endIdx; ++i) {
            // 如果当前位为数字，设numFlag为true
            if(isdigit(s[i])) {
                numFlag = true;
            }
            // 如果当前位为小数点，且前面没有出现过小数点或e或E，则设dotFlag为true
            else if(s[i] == '.' && !dotFlag && !eFlag) {
                dotFlag = true;
            }
            // 如果当前位为e或E，则需要前面没有出现过e或E且已经出现过数字
            else if((s[i] == 'e' || s[i] == 'E') && numFlag && !eFlag) {
                eFlag = true;
                // 为避免出现"1e"的情况，需要将numFlag设为false
                numFlag = false;
            }
            // 如果当前位为正负号，则当前下标为0或前一位是e或E
            else if((s[i] == '+' || s[i] == '-') && (i == idx || s[i-1] == 'e' || s[i-1] == 'E')) {
                continue;
            }
            // 除上述几种情况外其他所有情况均为非法
            else {
                return false;
            }
        }

        return numFlag;         // 任何合法情况都需要有数字，即如果s合法则numFlag必为true
    }
};
