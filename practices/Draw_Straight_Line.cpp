#include <vector>

using namespace std;

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);

        for(int i = x1; i <= x2; ++i) {
            // y * w / 32 represents the number of pixels before the y-th
            // row (0-indexed). i / 32 represents the row number. 
            res[i / 32 + y * w / 32] |= (1 << (31 - i % 32));
        }

        return res;
    }
};
