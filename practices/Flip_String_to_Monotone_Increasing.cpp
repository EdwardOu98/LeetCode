#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // The idea is to split the array into two halves. In the
    // left half, we need to count the number of 1's to flip
    // so that we can have all 0 in the left half. In the right
    // half, we need to count the number of 0's to flip so that
    // we can have all 1's in the right half. Keep track of the
    // the ones and flips as we iterate through the string, and
    // keep the smaller one as we meet a new character
    int minFlipsMonoIncr(string s) {
        int flips = 0, ones = 0;
        for(char c : s) {
            if(c == '1') {
                ++ones;
            }
            else {
                ++flips;
            }
            flips = min(flips, ones);
        }

        return flips;
    }
};
