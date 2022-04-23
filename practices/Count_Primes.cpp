#include <cstring>

using namespce std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) {
            return 0;
        }
        
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        
        // If a number n is divisible by some number p,
        // we know that n = p * q. And because q <= p, 
        // we can derive that n >= p * p or p <= sqrt(n).
        // Thus, for the outer loop, we only need to consider
        // numbers up to sqrt(n). To speed up the calculation,
        // we use i * i < n to avoid the expensive funtion of
        // sqrt()
        for(int i = 2; i * i < n; ++i) {
            // If the current number is not a prime number, 
            // we skip the current loop
            if(!isPrime[i]) {
                continue;
            }
            // For the inner loop, we calculate the multiples
            // i and mark them as false
            for(int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        
        int count = 0;
        for(int i = 2; i < n; ++i) {
            if(isPrime[i]) {
                ++count;
            }
        }
        
        return count;
    }
};
