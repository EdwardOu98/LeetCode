using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // If n is less than 1, than its always false
        if(n < 1) {
            return false;
        }
        
        while(n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }
};
