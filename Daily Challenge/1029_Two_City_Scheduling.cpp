#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // sort the array by the difference between travelling to city
    // A and travelling to city B in accending order. That is, if
    // it's cheaper for the person to travel to city A than to city
    // B, he will be on the first half of the sorted array. Otherwise
    // he will be on the second half of the array
    static bool myComp(vector<int>& a, vector<int>& b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(); // size of the costs array
        int res = 0;
        
        sort(costs.begin(), costs.end(), myComp);
        
        for(int i = 0; i < n / 2; ++i) {
            res += costs[i][0] + costs[i + n / 2][1];
        }
        
        return res;
    }
};
