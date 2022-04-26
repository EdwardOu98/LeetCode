using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // If n is negative or 0, it can't be a power of two. 
        // If n is a power of two and we do a bit-wise AND
        // with n - 1, the result should be 0. For example: 
        // 2 - 10, 1 - 01, 2 & 1 = 10 & 01 = 00. 
        // 4 - 100, 3 - 011, 4 & 3 = 100 & 011 = 000. 
        return (n > 0) && ((n & (n-1)) == 0);
    }
};
