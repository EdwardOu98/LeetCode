using namespace std;

class Solution {
public:
    // Use discussion post: https://leetcode.com/problems/mirror-reflection/discuss/141773/C%2B%2BJavaPython-1-line-without-using-any-package-or
    // as basis of this solution
    int mirrorReflection(int p, int q) {
        int m = 1, n = 1; // m is the number of rooms, n is the number of beams
                          // we need to find the m and n that satisfy the equation
                          // m * p = n * q
        
        while((m * p) != (n * q)) {
            ++n;
            m = (n * q) / p;
        }
        
        // When we have an even number of beams, it means the last beam must
        // point to a corner on the left side, and the only possible corner
        // is 2.
        // When we have an odd number of beams, the last beam must point to
        // a corner on the right side. When the number of rooms is odd, the
        // corner is 1. When the number of rooms is even, the corer is 0.
        if(n % 2 == 0 && m % 2 == 1) {
            return 2;
        }
        if(n % 2 == 1) {
            return (m % 2 == 0) ? 0 : 1;
        }
        
        return -1;
    }
};
