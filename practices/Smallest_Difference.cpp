#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int m = a.size(), n = b.size();
        // Use long to avoid overflow
        long diff = INT_MAX;
        int i = 0, j = 0;

        while(i < m && j < n) {
            // Calculate the difference between two current elements
            diff = min(diff, abs((long) a[i] - (long) b[j]));
            // If the current element in a is smaller than or equal to
            // the current element in b, increment i. Otherwise, increment j
            if(a[i] <= b[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }

        return diff;
    }
};
