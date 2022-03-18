#include <string>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        if(str.empty()) {
            return 0;
        }

        int idx = str.find_first_not_of(' ');

        if(idx == -1) {
            return 0;
        }

        int res = 0, sign = 1;
        // 为确保结果不会溢出而需要的判断条件
        int base = INT_MAX / 10, remainder = INT_MAX % 10;

        if(str[idx] == '+' || str[idx] == '-') {
            sign = (str[idx] == '+') ? 1 : -1;
            ++idx;
        }

        while(idx < str.length() && isdigit(str[idx])) {
            int temp = str[idx] - '0';
            // 如果当前res已经大于base或res等于base且temp大于remainder，则说明会发生溢出，
            // 需要根据符号返回INT_MAX或INT_MIN
            if((res > base) || (res == base && temp > remainder)) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + temp;
            ++idx;
        }

        return res * sign;
    }
};
