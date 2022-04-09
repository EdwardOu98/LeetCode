#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    struct comp {
        bool operator() (const pair<int, int> p1, const pair<int, int> p2) {
            return p1.second > p2.second;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int num : nums) {
            ++mp[num];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for(pair<int, int> p : mp) {
            pq.push(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res;
        for(int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};
