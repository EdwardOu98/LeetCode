#include <string>

using namespace std;

class Solution {
/* 数字范围    数量  位数    占多少位
    1-9        9      1       9
    10-99      90     2       180
    100-999    900    3       2700
    1000-9999  9000   4       36000  ...

    例如 2901 = 9 + 180 + 2700 + 12 即一定是4位数,第12位   n = 12;
    数据为 = 1000 + (12 - 1)/ 4  = 1000 + 2 = 1002
    定位1002中的位置 = (n - 1) %  4 = 3    s[3] = 2;
*/
public:
    int findNthDigit(int n) {
        if(n < 10) {
            return n;
        }
        int digit = 1;
        long start = 1;
        long count = 9;
        // 先确定目标数字是几位数
        while(n > count) {
            n -= count;
            ++digit;
            start *= 10;
            count = digit * start * 9;
        }
        // 确定目标数字
        long num = start + (n - 1) / digit;

        // 取出目标位上的数字并返回
        string str = to_string(num);
        return str[(n - 1) % digit] - '0';
    }
};
