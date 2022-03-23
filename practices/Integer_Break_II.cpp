using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int cuttingRope(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        long product = 1;
        while(n > 4) {
            product = (product * 3) % MOD;
            n -= 3;
        }

        return (product * n) % MOD; 
    }
};
