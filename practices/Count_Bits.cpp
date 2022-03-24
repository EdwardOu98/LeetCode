#include <vector>

using namespace std;

class Solution {
private:
    vector<int> refinedApproach(int& n) {
        // 如果i是偶数，则i相当于将i/2左移一位的结果，即i和i/2的二进制形式中1的个数是一样的；
        // 如果i是奇数，则i相当于将i/2左移一位后再将最低位设为1的结果，即i的二进制形式中的1的
        // 个数比i-2中的多1。根据上述规律可得以下代码
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1); // 右移一位等效于i/2，加上i&1则相当于将
                                            // 最低位设为0(偶数)或1(奇数)
        }
        return res;
    }

    vector<int> intuitiveApproach(int& n) {
        int temp, counter;
        vector<int> res;
        for(int i = 0; i <= n; ++i) {
            temp = i;
            counter = 0;
            while(temp) {
                // 如果当前位为1，则counter自增1
                if(temp & 1) {
                    ++counter;
                }
                // temp右移一位
                temp >>= 1;
            }
            res.push_back(counter);
        }

        return res;
    }
public:
    vector<int> countBits(int& n) {
        // return intuitiveApproach(n);
        return refinedApproach(n);
    }
};
