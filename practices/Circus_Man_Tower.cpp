#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii; // height - weight

    static bool comp(pii& a, pii& b) {
        if(a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        if(height.empty()) {
            return 0;
        }
        vector<pii> p;
        int n = height.size();
        for(int i = 0; i < n; ++i) {
            p.push_back({height[i], weight[i]});
        }

        sort(p.begin(), p.end(), comp);

        vector<int> res;
        for(int i = 0; i < n; ++i) {
            auto it = lower_bound(res.begin(), res.end(), p[i].second);
            if(it == res.end()) {
                res.push_back(p[i].second);
            }
            else {
                *it = p[i].second;
            }
        }

        return res.size();
    }
};
