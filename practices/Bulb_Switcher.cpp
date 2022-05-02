#include <cmath>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        // For a light bulb to be on at the end of the function,
        // it must have been toggled for an odd number of times. 
        // And for it to be toggled for an odd number of times, 
        // its index (1-indexed) must be a prefect square. Because
        // only perfect squares can have factor pairs such that 
        // one of the pair is consisted of two same numbers (i.e. 
        // 4 - {1, 4}, {2, 2}, 9 - {1, 9}, {3, 3}, 16 - {1, 16}, 
        // {2, 8}, {4, 4}). In order words, only perfect square
        // numbers have odd number of factors. Now the problem
        // becomes finding the number of perfect squares smaller
        // than or equal to n. In order to have 1 perfect square
        // numbers, we need at least 1^2 = 1 number in the sequence.
        // To have 2 perfect square numbers, we need 2 ^ 2 = 4 numbers
        // in the sequence. Now we have n number of sequence, the 
        // number of perfect squares smaller than or equal to n is
        // sqrt(n). 
        return sqrt(n);
    }
};
