using namespace std;

class Solution {
private:
    int hammingDistance(int A, int B) {
        // Find the hamming distance of A and B
        unsigned int x = A ^ B;
        int count = 0;

        while(x != 0) {
            x &= (x - 1);
            ++count;
        }

        return count;
    }
public:
    int convertInteger(int A, int B) {
        int count = 0;
        for(int i = 0; i < 32; ++i) {
            int a = A & (1 << i);
            int b = B & (1 << i);
            if(a ^ b) {
                ++count;
            }
        }

        return count;
    }
};
