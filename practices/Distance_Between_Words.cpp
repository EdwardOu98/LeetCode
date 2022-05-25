#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> w1, w2;
        int n = words.size();
        // Record all indices where word1 and word2 appear
        for(int i = 0; i < n; ++i) {
            if(words[i] == word1) {
                w1.push_back(i);
            }
            else if(words[i] == word2) {
                w2.push_back(i);
            }
        }

        int n1 = w1.size(), n2 = w2.size();
        int res = INT_MAX;
        int i = 0, j = 0;

        // Find the minimum difference between the indices
        while(i < n1 && j < n2) {
            res = min(res, abs(w1[i] - w2[j]));
            if(w1[i] < w2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }

        return res;
    }
};
