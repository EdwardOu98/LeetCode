#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;
        for(const char& c : s){
            switch(c){
                case '1':
                    ones++;
                    break;
                default:
                    flips++;
            }
            flips = min(ones, flips);
        }
        return flips;
    }
};
