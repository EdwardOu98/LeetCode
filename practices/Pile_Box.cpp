#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        // Sort the input by the boxes' width, depth, and height
        // so that we don't miss the larger boxes in the front
        sort(box.begin(), box.end());

        // dp[i] is the maximum height we can achieve by stacking
        // the boxes from the first one to the i-th one (0-indexed)
        vector<int> dp(n, 0);

        for(int i = 0; i < n; ++i) {
            dp[i] = box[i][2];
            for(int j = 0; j < i; ++j) {
                // If the dimension of the current box is larger than the j-th
                // box, calculate the maximum height we can achieve
                if((box[i][0] > box[j][0]) && (box[i][1] > box[j][1]) && (box[i][2] > box[j][2])) {
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                }
            }
        }

        int maxEle = 0;
        // Find the maximum height we can achieve
        for(int& h : dp) {
            maxEle = max(maxEle, h);
        }

        return maxEle;
    }
};
