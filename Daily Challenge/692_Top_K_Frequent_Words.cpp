#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<string, int> psi;

class comp {
public:
    bool operator() (const psi& a, const psi& b) {
        if(a.second != b.second) {
            return a.second > b.second;
        }
        
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        
        for(auto& w : words) {
            ++count[w];
        }
        
        priority_queue<psi, vector<psi>, comp> pq;
        
        for(auto& p : count) {
            pq.push(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> res;
        
        while(!pq.empty()) {
            string s = pq.top().first;
            pq.pop();
            res.insert(res.begin(), s);
        }
        
        return res;
    }
};
