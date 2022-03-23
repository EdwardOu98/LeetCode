using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int orgn = n; // 保存原本的n
        int res = 0;
        long base = 1; // 使用long型避免出现溢出

        while(n > 0) {
            int curr_pos = n % 10; // 当前位
            int upper_pos = n / 10; // 高位
            if(curr_pos > 1) {
                res += upper_pos * base + 1 * base;
            }
            else if(curr_pos == 1) {
                res += upper_pos * base + (orgn % base + 1);
            }
            else {
                res += upper_pos * base;
            }
            base *= 10;
            n /= 10;
        }

        return res;
    }
};
