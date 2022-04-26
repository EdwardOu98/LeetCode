#include <algorithm>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n == 0) {
            return 0;
        }
        
        int counter = 0;
        for(long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            counter += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        
        return counter;
    }
};
