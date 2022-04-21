#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    // Find the greatest common divider of 
    // a and b
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        // If the input list contains less than two
        // points, then return the number of points
        if(n < 2) {
            return n;
        }
        
        int res = 0; // Number of points 
        int duplicates; // Find number of duplicate points
        unordered_map<string, int> slopes;  // map points to the slope of
                                            // a line
        int dx, dy; // Difference between the x and y coordinates of two points
        int divider;// The gcd of dx and dy
        
        
        for(int i = 0; i < n; ++i) {
            duplicates = 1;
            slopes.clear();
            
            for(int j = i + 1; j < n; ++j) {
                // If the jth point has the same x and y coordinates as the ith
                // point, increment duplicates
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicates;
                }
                else {
                    dx = points[j][0] - points[i][0];
                    dy = points[j][1] - points[i][1];
                    divider = gcd(dx, dy);
                    ++slopes[to_string(dx / divider) + "_" + to_string(dy / divider)];
                }
            }
            
            res = max(res, duplicates);
            for(auto p : slopes) {
                res = max(res, p.second + duplicates);
            }
        }
        
        return res;
    }
};
