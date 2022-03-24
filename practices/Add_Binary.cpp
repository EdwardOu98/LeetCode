#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        int d1, d2;
        string res;
        while(i >= 0 && j >= 0) {
            int d1 = a[i] - '0', d2 = b[j] - '0';
            res += ((d1 ^ d2 ^ carry) ? "1" : "0");

            carry = (d1 + d2 + carry) >> 1;
            --i;
            --j;
        }

        while(i >= 0) {
            d1 =  a[i] - '0';
            res += ((d1 ^ carry) ? "1" : "0");

            carry = d1 & carry;

            --i;
        }

        while(j >= 0) {
            d2 =  b[j] - '0';
            res += ((d2 ^ carry) ? "1" : "0");

            carry = d2 & carry;

            --j;
        }

        if(carry) {
            res += "1";
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
