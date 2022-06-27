#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // A decimal number is called deci-binary if each of its
    // digit is either 0 or 1 without any leading 0's (such as
    // 10, 11, 101). Given a positive integer, the number of
    // deci-binary numbers we need to sum up to this integer
    // depends on the maximum digit in this number. For example,
    // to form 32, we need 3 deci-binary numbers (10, 11, 11). 
    int minPartitions(string n) {
        int maxDigit = 0;
        
        for(char& c : n) {
            maxDigit = max(maxDigit, c - '0');
        }
        
        return maxDigit;
    }
};
