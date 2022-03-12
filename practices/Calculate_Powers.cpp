using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }

        if(n < 0) {
            return (1.0 / x) * myPow(1.0 / x, -(n + 1));
        }

        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};
