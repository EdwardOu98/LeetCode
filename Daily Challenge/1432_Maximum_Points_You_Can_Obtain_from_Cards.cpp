#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        // Record the sum of all elements in the sliding window
        for(int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }
        
        // If k is equal to the length of the cardPoints array, 
        // directly return the sum of all elements 
        if(k == cardPoints.size()) {
            return total;
        }
        
        int best = total;
        
        // Each time we remove one element from the right side
        // of the window and add an element from the back of the
        // cardPoints array, record the difference between the two
        // cards and the maximum points we can obtain in this process
        for(int i = k - 1, j = cardPoints.size() - 1; i >= 0; --i, --j) {
            total += cardPoints[j] - cardPoints[i];
            best = max(best, total);
        }
        
        return best;
    }
};
