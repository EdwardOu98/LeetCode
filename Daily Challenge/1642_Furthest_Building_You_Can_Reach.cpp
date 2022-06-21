#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; // Stores the height differences 
        int n = heights.size() - 1;
        
        for(int i = 0; i < n; ++i) {
            // Calculate the height difference between the current and 
            // the next building
            int diff = heights[i+1] - heights[i]; 
            // If the next building is higher than the current one, 
            // add the negated difference to the priority queue. 
            if(diff > 0) {
                pq.push(-diff);
            }
            // If the ladders are not enough, we have to use bricks
            if(pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            // If we don't have enough bricks to reach the next building, 
            // the current building is the furthest one we can reach
            if(bricks < 0) {
                return i;
            }
        }
        
        return n;
    }
};
