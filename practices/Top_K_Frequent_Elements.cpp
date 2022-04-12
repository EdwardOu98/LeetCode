#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
private:
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }

    vector<int> implementation1(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        vector<int> res;

        for(int num : nums) {
            ++umap[num];
        }

        vector<pair<int, int>> temp(umap.begin(), umap.end());

        sort(temp.begin(), temp.end(), comp);

        for(int i = 0; i < k; ++i) {
            res.push_back(temp[i].first);
        }

        return res;
    }

    vector<int> implementation2(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        vector<int> res;

        for(int num : nums) {
            ++umap[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it : umap) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return implementation2(nums, k);
    }
};
