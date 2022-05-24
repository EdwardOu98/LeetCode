using namespace std;

class Solution {
public:
    int numberOf2sInRange(int n) {
        long pre = n, cur = n % 10, post = 0, bit = 1;
        int count = 0;

        while(pre > 0) {
            pre /= 10;
            if(cur == 2) {
                count += pre * bit + post + 1;
            }
            else if(cur > 2) {
                count += (pre + 1) * bit;
            }
            else {
                count += pre * bit;
            }

            post += bit * cur;
            bit *= 10;
            cur = pre % 10;
        }

        return count;
    }
};
