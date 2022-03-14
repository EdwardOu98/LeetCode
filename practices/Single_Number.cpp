#include <vector>;

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            int count = 0; // 记录每一位上1出现的次数
            int index = 1 << i;
            for(int n : nums) {
                if(n & index) {
                    ++count;
                }
            }

            // 如果该位上出现1的次数与3取余后为1，则说明结果数字上该位为1
            if((count % 3) == 1) {
                res |= index;
            }
        }

        return res;
    }
};
