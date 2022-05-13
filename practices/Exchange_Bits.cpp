using namespace std;

class Solution {
public:
    int exchangeBits(int num) {
        // Extract the bits on the even and odd positions
        int evenPos = num & 0xaaaaaaaa;
        int oddPos = num & 0x55555555;

        return (evenPos >> 1) | (oddPos << 1);
    }
};
