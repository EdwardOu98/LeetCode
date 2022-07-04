#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 2) {
            return n;
        }
        
        int leftToRight[n];
        int rightToLeft[n];
        
        // Initialize the two arrays
        for(int i = 0; i < n; ++i) {
            leftToRight[i] = rightToLeft[i] = 1;
        }
        
        // Calculate the minimum number of candies needed
        // only in the left to right direction
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i-1]) {
                leftToRight[i] = leftToRight[i-1] + 1;
            }
        }
        
        // Calculate the minimum number of candies needed
        // only in the right to left direction
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1]) {
                rightToLeft[i] = rightToLeft[i+1] + 1;
            }
        }
        
        int total = 0;
        
        // Sum up the candies needed for each child, which
        // is the maximum number of candies needed in either
        // direction
        for(int i = 0; i < n; ++i) {
            total += max(leftToRight[i], rightToLeft[i]);
        }
        
        return total;
    }
};
