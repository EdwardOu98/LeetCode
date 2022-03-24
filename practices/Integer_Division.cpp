#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        // 溢出
        if(a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        // 被除数为0或除数为1，直接返回被除数
        if(a == 0 || b == 1) {
            return a;
        }
        // 如果除数为-1，则返回-a(因为INT_MAX取负后不会溢出所以可以直接返回-INT_MAX)
        else if(b == -1) {
            return -a;
        }

        int res = 0;

        // 符号为a和b的异或结果
        int sign = (a < 0) ^ (b < 0) ? -1 : 1;

        // 用无符号数防止溢出
        unsigned int ua = abs(a);
        unsigned int ub = abs(b);

        // 从高位开始右移，减去除数的倍数
        // 当ua>>i大于ub时，则ua小于ub<<i
        for(int i = 31; i >= 0; --i) {
            if((ua >> i) >= ub) {
                ua -= ub << i;
                res += 1 << i;
            }
        }

        return sign > 0 ? res : -res;
    }
};
