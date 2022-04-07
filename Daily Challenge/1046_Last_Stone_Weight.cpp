#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // Simply simulate the process with a priority queue where 
    // elements are sorted in decending order. Each time we pick
    // the two elements with the greatest weight and collide them
    // with each other and calculate the result based on the rule
    // described. 
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(abs(a - b));
        }
        
        return pq.top();
    }
};
