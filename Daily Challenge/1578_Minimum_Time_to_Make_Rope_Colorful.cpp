#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0, currMaxTime = 0;
        
        for(int i = 0; i < colors.length(); ++i) {
            if(i > 0 && colors[i] != colors[i-1]) {
                currMaxTime = 0;
            }
            
            totalTime += min(currMaxTime, neededTime[i]);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }
        
        return totalTime;
    }
};
