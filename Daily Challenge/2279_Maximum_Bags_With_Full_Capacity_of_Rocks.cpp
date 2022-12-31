#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int num_Full = 0;
        vector<int> diff(n, 0);

        for(int i = 0; i < n; ++i) {
            diff[i] = capacity[i] - rocks[i];
        }

        sort(diff.begin(), diff.end());

        for(int i = 0; i < n; ++i) {
            if(diff[i] > 0 && diff[i] <= additionalRocks) {
                additionalRocks -= diff[i];
                diff[i] = 0;
            }

            if(diff[i] == 0) {
                ++num_Full;
            }
        }

        return num_Full;
    }
};
