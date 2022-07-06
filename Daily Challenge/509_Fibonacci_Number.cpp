using namespace std;

class Solution {
private:
    // Normal iterative approach
    int iterative(int n) {
        if(n < 2) {
            return n;
        }
        
        int fibs[n+1];
        fibs[0] = 0;
        fibs[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            fibs[i] = fibs[i-1] + fibs[i-2];
        }
        
        return fibs[n];
    }
public:
    // Space-optimized iterative approach
    int fib(int n) {
        if(n < 2) {
            return n;
        }
        
        // Stores only the two previous fibonacci number and 
        // the current result
        int a = 0, b = 1, c = 0;
        
        for(int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
