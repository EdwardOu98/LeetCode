#using namespace std;

class Solution {
public:
    int add(int a, int b) {
        unsigned int sum = 0, carry = 0;
        while(b != 0) {
            sum = a ^ b; // Calculate the part without the carry part
            carry = (unsigned int) (a & b) << 1; // Calculate the carry
            a = sum; // Save the result part to a
            b = carry; // Save the carry to b
        }

        return a;
    }
};
