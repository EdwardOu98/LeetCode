using namespace std;

class Solution {
// To convert a base-10 decimal to a binary decimal, 
// we multiply the number by 10. If the number on the
// left side of the decimal point is 1, we add 1 to 
// the next bit of the binary expression, otherwise add 0. 
// The part on the right side of the decimal point are
// used in the next round of calculation. 
public:
    string printBin(double num) {
        string res = "0.";
        int i = 0;

        while(i < 32 && num != 0) {
            num *= 2;
            if(num >= 1) {
                res += "1";
                num -=1;
            }
            else {
                res += "0";
            }
            ++i;
        }

        // If num is 0 after the conversion, it means the input can
        // be represented by a 32-bit binary number. Otherwise, return
        // "ERROR" because the input cannot be represented by 32-bit
        // binary number precisely
        return num == 0.0 ? res : "ERROR";
    }
};
