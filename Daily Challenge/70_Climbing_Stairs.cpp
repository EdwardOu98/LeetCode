using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        
        int fibs[n];
        fibs[0] = 1;
        fibs[1] = 2;
        
        for(int i = 2; i < n; ++i) {
            fibs[i] = fibs[i-1] + fibs[i-2];
        }
        
        return fibs[n-1];
    }
};
