#include <vector>

using namespace std;

class Solution {
private:
    int nextMax(long num) {
        // Find the lowest bits with value 1
        long x = num & -num;
        // Set those bits to 0 and set the first 0 to the left
        // of the region to 1
        long y = x + num;
        // Move the region selected in 1 to the right until the
        // number of remaining 1's is 1 less than the original
        // count. Then we or it with y
        return (num & ~y) / x >> 1 | y;
    }
public:
    vector<int> findClosedNumbers(int num) {
        if(num == 1) {
            return {2, -1};
        }
        if(num == INT_MAX) {
            return {-1, -1};
        }

        int upper = nextMax(num);
        int lower = ~nextMax(~num);
        if(upper < 0) {
            upper = -1;
        }
        return {upper, lower};
    }
};
