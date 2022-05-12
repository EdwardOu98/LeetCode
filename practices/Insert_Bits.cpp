using namespace std;

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        // Mark the i- to j-th bit of N as 0
        for(int k = i; k <= j; ++k) {
            if((N & (1 << k)) != 0) {
                N -= (1 << k);
            }
        }

        // Bit-wise or of N and M left shift by i
        N |= (M << i);

        return N;
    }
};
