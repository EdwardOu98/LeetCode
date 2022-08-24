using namespace std;

class Solution {
private:
    bool NaiveApproach(int n) {
        if(n <= 0) {
            return false;
        }
        
        while(n % 4 == 0) {
            n /= 4;
        }
        
        return n == 1;
    }
public:
    bool isPowerOfFour(int n) {
        // If a number is a power of 4, it must satisfy the following properties:
        // - n & (n - 1) = 0
        // - n - 1 is a multiple of 3
        // Examples: 4 - 100, 3 - 011; 16 - 10000, 15 - 01111; 64 - 1000000, 63 - 0111111, etc.
        return n > 0 && (n & (n - 1)) == 0 && ((n - 1) % 3) == 0;
    }
};
