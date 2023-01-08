#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int count = 0, minEnd = INT_MAX;
        
        for(vector<int>& p : points) {
            if(p[0] > minEnd) {
                ++count;
                minEnd = p[1];
            }
            else {
                minEnd = min(minEnd, p[1]);
            }
        }
        
        return count + !points.empty();
    }
};
