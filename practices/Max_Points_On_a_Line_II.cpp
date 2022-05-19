#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) {
            return {0, 1};
        }

        vector<int> res(2); // Result array
        int duplicates; // Number of duplicate points
        int i, j; // Loop varaibles
        int max_Len = 0; // Maximum count of points on the same line
        for(i = 0; i < n - 1; ++i) {
            map<double, vector<int>> mp;
            double max_temp = 0;
            for(j = i + 1; j < n; ++j) {
                double slope;
                if(points[i][1] == points[j][1]) {
                    slope = 0.0;
                }
                else if(points[i][0] == points[j][0]) {
                    slope = (double) INT_MAX;
                }
                else {
                    slope = (points[i][1] - points[j][1]) / (double) (points[i][0] - points[j][0]);
                }
                mp[slope].push_back(j);
                if(mp[slope].size() > max_Len) {
                    if(mp[slope].size() >= 1) {
                        res[0] = i;
                        res[1] = mp[slope][0];
                    }
                    max_Len = mp[slope].size();
                    max_temp = slope;
                }
            }
        }

        return res;
    }
};
