#include <cstdint>

using namespace std;

class Solution {
public:
    int maximum(int a, int b) {
        uint64_t diff = (uint64_t) a - (uint64_t) b;
        int k = diff >> 63;
        return a * (k ^ 1) + b * k;
    }
};
