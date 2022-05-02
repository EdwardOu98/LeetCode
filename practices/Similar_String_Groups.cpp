#include <string>
#include <vector>
#include <numeric> // iota

using namespacee std;

class Solution {
private:
    bool isSimilar(string& a, string& b) {
        int diff = 0; // Number of indices with different characters
        for(int i = 0; i < a.length(); ++i) {
            if(a[i] != b[i]) {
                ++diff;
            }
            // If there are more than 2 indices with different characters,
            // return false
            if(diff > 2) {
                return false;
            }
        }
        return true;
    }

    // Find which group x belongs to
    int find(int group[], int x) {
        return x == group[x] ? x : find(group, group[x]);
    }

    // Try to merge the two groups
    bool merge(int group[], int x, int y) {
        int gx = find(group, x);
        int gy = find(group, y);
        // If x and y doesn't belong to the same group, 
        // we can merge the two groups 
        if(gx != gy) {
            group[gx] = gy;
            return true;
        }
        return false;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int group[n];
        iota(group, group + n, 0);  // This is a function from the <numeric>
                                    // library. Its purpose is to assign the
                                    // the array group with numbers from 0 to
                                    // n - 1
        int res = n; // Initially, there are n individual groups. Each word in
                     // the input array forms its own group
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                // If the two words are similar and they doesn't belong to the 
                // same group, we can merge them into one group and reduce the 
                // group count by 1
                if(isSimilar(strs[i], strs[j]) && merge(group, i, j)) {
                    --res;
                }
            }
        }

        return res;
    }
};
