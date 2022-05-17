#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    const double E = 1e-6;

    // Check whether x is in between s->e or e->s 
    bool inLine(double x, double s, double e) {
        if(abs(x - s) < E || abs(x - e) < E) {
            return true;
        }

        return ((x - s > 0) && (e - x > 0)) || ((x - e > 0) && (s - x > 0));
    }
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        // Get the coordinates
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];

        // Get the coefficient of the two lines
        // Line 1: a11(x) + a12(y) = b1
        // Line 2: a21(x) + a22(y) = b2
        int a11 = y2 - y1, a12 = x1 - x2, b1 = x1 * y2 - x2 * y1;
        int a21 = y4 - y3, a22 = x3 - x4, b2 = x3 * y4 - x4 * y3;
        // Get the determinant of the lines
        int D = a11 * a22 - a12 * a21, D1 = b1 * a22 - a12 * b2, D2 = b2 * a11 - b1 * a21;
        // If the two lines are parallel to each other
        if(D == 0 && D1 == 0) {
            // If they are not the same line
            if(min(x3, x4) > max(x1, x2) || min(x1, x2) > max(x3, x4)) {
                return {};
            }
            if(min(y3, y4) > max(y1, y2) || min(y1, y2) > max(y3, y4)) {
                return {};
            }
            // If they are the same line
            vector<vector<int>> v{{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
            sort(v.begin(), v.end());
            // The second to the smallest one is the answer
            return {(double) v[1][0], (double) v[1][1]};
        }
        // If the two lines are not parallel to each other
        if(D != 0) {
            // Calculate the crossing point
            double x0 = D1 / (double) D, y0 = D2 / (double) D;
            // If the crossing point is on both lines, then this is the answer
            if(inLine(x0, x1, x2) && inLine(x0, x3, x4) && inLine(y0, y1, y2) && inLine(y0, y3, y4)) {
                return {x0, y0};
            }
        }

        return {};
    }
};
