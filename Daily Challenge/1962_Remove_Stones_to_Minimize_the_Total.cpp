#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        while(k--) {
            int num = pq.top();
            pq.pop();
            pq.push(num - num / 2);
        }

        int res = 0;

        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};
