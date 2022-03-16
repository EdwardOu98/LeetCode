using namespace std;

class Solution {
// 思路：任何大于1的数都可以由2和3相加组成；因为
// 2*2 = 1*4， 2*3 > 1*5， 所以将数字拆成2和3
// 能得到的积最大。又因为2*2*2 < 3*3，所以3越多
// 得到的积也越大。
public:
    int cuttingRope(int n) {
        if(n <= 3) {
            return n - 1;
        }

        int product = 1;
        while(n > 4) {
            product *= 3;
            n -= 3;
        }

        return product * n;
    }
};
