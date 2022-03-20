#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Time complexity: O(n), Space Complexity: O(1)
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Keep 3 counters, one for all numbers in tops, one for all numbers
        // in bottoms, and one for numbers that appears both in tops and bottoms
        // and at the same position
        int counterTop[6] = {0}, counterBottom[6] = {0}, counterBoth[6] = {0};
        int n = tops.size(), i;
        
        for(i = 0; i < n; ++i) {
            ++counterTop[tops[i] - 1];
            ++counterBottom[bottoms[i] - 1];
            if(tops[i] == bottoms[i]) {
                ++counterBoth[tops[i] - 1];
            }
        }
        
        // If rotation could be done, the inputs must satisfy the following:
        // occurrence of number i in tops + occurrence of number i in bottoms
        // - occurrence of number i in both inputs with the same index = n
        for(i = 0; i < 6; ++i) {
            if(counterTop[i] + counterBottom[i] - counterBoth[i] == n) {
                return n - max(counterTop[i], counterBottom[i]);
            }
        }
        
        return -1;
    }
};
