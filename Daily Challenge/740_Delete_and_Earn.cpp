#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        int counts[n];
        
        memset(counts, 0, sizeof(counts));
        
        for(int num : nums) {
            counts[num] += num;
        }
        
        int take = 0, skip = 0;
        
        for(int i = 0; i < n; ++i) {
            int take_i = skip + counts[i];
            int skip_i = max(skip, take);
            take = take_i;
            skip = skip_i;
        }
        
        return max(take, skip);
    }
};
