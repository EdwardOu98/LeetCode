#include <cmath>
#include <vector>

using namespace std;

class Solution {
private:
    // Calculate the manhattan distancee between two points
    int manhattanDistance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    // Get the next node to be added to the MST
    int getNextNode(int minDist[], bool inMST[], int n) {
        int idx = 0, dist = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(!inMST[i] && minDist[i] < dist) {
                dist = minDist[i];
                idx = i;
            }
        }
        return idx;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int minDist[n]; // Stores the minimum distance from the
                        // the current MST to the node
        bool inMST[n];  // Record whether a node is in the MST
        int pointsIncluded; // Number of points in MST
        int minCost = 0; // It takes 0 cost to bring the first point
                         // into MST
        
        // Initialize data
        minDist[0] = 0;
        inMST[0] = true;
        pointsIncluded = 1;
        
        for(int i = 1; i < n; ++i) {
            inMST[i] = false;
            minDist[i] = manhattanDistance(points[0], points[i]);
        }
        
        while(pointsIncluded < n) {
            // Get the next node to add to the MST
            int nextP = getNextNode(minDist, inMST, n);
            // Add it to the MST
            inMST[nextP] = true;
            // Update the minimum cost to create the MST
            minCost += minDist[nextP];
            // Update the number of points in MST
            ++pointsIncluded;
            
            // Update the minDist array
            for(int i = 0; i < n; ++i) {
                if(!inMST[i]) {
                    int newDist = manhattanDistance(points[nextP], points[i]);
                    if(newDist < minDist[i]) {
                        minDist[i] = newDist;
                    }
                }
            }
        }
        
        return minCost;
    }
};
