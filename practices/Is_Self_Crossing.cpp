#include <vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        // If the direction changes less than 3 times, the path
        // can never be self-crossing
        if(n <= 3) {
            return false;
        }
        
        // If the distance travelled after the third direction change
        // is more than the distance in the first movement, then we can
        // say that the spiral is growing
        bool growingSpiral = distance[2] > distance[0];
        
        for(int i = 3; i < n; ++i) {
            // If the spiral is shrinking (growingSpiral = false) and the
            // current distance travelled is more than the distance travelled
            // in the opposite direction previously, then we can say that the
            // path is self-crossing
            if(!growingSpiral && distance[i] >= distance[i-2]) {
                return true;
            }
            // If we have a growing spiral before and now it turns to shrinking
            if(growingSpiral && distance[i] <= distance[i-2]) {
                // Set growingSpiral to false
                growingSpiral = false;
                // If the current distance travelled is equal to the distance 
                // travelled in the opposite direction previously, or it's greater
                // than the total displacement in the same direction (up-down or
                // left-right), then we need to update the boundary
                if((distance[i] == distance[i-2]) || 
                   ((i > 3) && (distance[i] >= (distance[i-2] - distance[i-4])))) {
                    distance[i-1] -= distance[i-3];
                }
            }
        }
        
        return false;
    }
};
