#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> res;
        int i, j;
        
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;

        for(i = 0; i < m; ++i) {
            for(j = 0; j < n; ++j) {
                pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }

        while(!pq.empty()) {
            res.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }

        return res;
    }
};
