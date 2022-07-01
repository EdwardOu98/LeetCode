#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort the boxes based on their unit size
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int maxCount = 0;
        
        for(auto& b : boxTypes) {
            // If the number of the current boxType exceeds the truckSize,
            // we can only fit truckSize boxes into the truck. 
            if(b[0] >= truckSize) {
                maxCount += (truckSize * b[1]);
                truckSize = 0;
                break;
            }
            // Otherwise, we can put all of the current boxType onto the truck.
            // Then we need to subtract the number of boxes we put on the truck
            // from the truckSize
            else {
                maxCount += (b[0] * b[1]);
                truckSize -= b[0];
            }
        }
        
        return maxCount;
    }
};
