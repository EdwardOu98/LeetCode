#include <vector>

using namespace std;

class Solution {
public:
    // 设数组中两个独特的数分别为A和B
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;

        // 求A xor B的结果
        for(int n : nums) {
            x ^= n;
        }

        // 通过一个flag来区分A和B
        int flag = x & (-x);
        int res = 0;

        for(int n : nums) {
            if(flag & n) {
                res ^= n;
            }
        }

        return {res, x ^ res};
    }
};
