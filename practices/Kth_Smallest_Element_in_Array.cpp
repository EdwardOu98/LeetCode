#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k == 0) {
            return {};
        }
        if(k == arr.size()) {
            return arr;
        }
        priority_queue<int, vector<int>, less<int>> pq;
        for(int& n : arr) {
            pq.push(n);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
