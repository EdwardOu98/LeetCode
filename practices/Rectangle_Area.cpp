using namespace std;

class Solution {
private:
    int area(int x1, int x2, int y1, int y2) {
        if(x1 > x2 || y1 > y2) {
            return 0;
        }
        
        return (x2 - x1) * (y2 - y1);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Find the parameter of the overlapping part of the two triangles
        int x1 = max(ax1, bx1), x2 = min(ax2, bx2), y1 = max(ay1, by1), y2 = min(ay2, by2);
        
        // The total area covered by the triangle is the sum of the area covered by the two 
        // triangles minus the overlapping area
        return area(ax1, ax2, ay1, ay2) + area(bx1, bx2, by1, by2) - area(x1, x2, y1, y2);
    }
};
