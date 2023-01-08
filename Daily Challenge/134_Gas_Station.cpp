#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n != cost.size()) {
            return -1;
        }
        
        int total = 0;          // Adds up the difference between the 
                                // gas and cost for each station
        int subSum = INT_MAX;   // Record the difference between the 
                                // gas and cost up to a certain point
        int start = 0;          // Record the starting station
        
        for(int i = 0; i < n; ++i) {
            total += gas[i] - cost[i];
            
            // If total is less then subSum, that means we don't have
            // enough fuel to start travelling up till the ith station.
            // Thus, we should try to start at the i+1th station
            if(total < subSum) {
                subSum = total;
                start = i + 1;
            }
        }
        
        // After iterating through the array, if the total is negative, 
        // that means we don't have enough fuel to complete a round trip
        // and return -1. Otherwise we return start % n
        return total < 0 ? -1 : start % n;
    }
};
