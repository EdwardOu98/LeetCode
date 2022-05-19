#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        // To divide a square into two equal parts, the line must pass through the
        // center of the square. Similarly, to divide two squares into equal parts,
        // the line must pass through both squares' center.

        // Let square1 hold the square that has a smaller x value
        if((square1[0] > square2[0]) || ((square1[0] == square2[0]) && (square1[1] > square2[1]))) {
            swap(square1, square2);
        }

        // Find the center of the two squares
        double r1 = square1[2] / 2.0, r2 = square2[2] / 2.0;
        double x1 = square1[0] + r1, y1 = square1[1] + r1;
        double x2 = square2[0] + r2, y2 = square2[1] + r2;

        // If the slope of the division line doesn't exist (parallel to the y-axis)
        if(x1 == x2) {
            return {x1, y1 - r1, x2, max(y1 + r1, y2 + r2)};
        }
        else {
            double slope = (y2 - y1) / (x2 - x1);
            double b = y1 - slope * x1;
            // If the absolute value of the slope is less than or equal to 1, the 
            // division line crosses the left and right edges of the squares
            if(abs(slope) <= 1) {
                double l = square1[0], r = max(x1 + r1, x2 + r2);
                return {l, slope * l + b, r, slope * r + b};
            }
            // If the absolute value of the slope is greater than or equal to 1,  
            // the division line crosses the up and down edges of the squares
            else {
                double down = min(square1[1], square2[1]), up = max(y1 + r1, y2 + r2);
                double xd = (down - b) / slope, xu = (up - b) / slope;
                if((xd < xu) || ((xd == xu) && (down < up))) {
                    return {xd, down, xu, up};
                }
                return {xu, up, xd, down};
            }
        }
    }
};
