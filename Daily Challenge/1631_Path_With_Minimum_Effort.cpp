#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
private:
    typedef pair<int, pair<int, int>> pip; // distance - x-coordinate, y-coordinate
    const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    // Idea: we can see the cells as vertices and they are connected by edges whose
    // weight is the difference between the height of two cells. Then the problem
    // becomes find the shortest path with the minimum weight on each edge
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(); // Dimension of the matrix
        
        priority_queue<pip, vector<pip>, greater<pip>> pq; // Stores the edge between
                                                           // two cells
        int dist[m][n]; // Stores the distance from (0, 0) to the current cell
        
        // Initialize the dist array. dist[0][0] is initialized to 0, and all
        // other cells are initialized to INT_MAX
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    dist[i][j] = 0;
                }
                else {
                    dist[i][j] = INT_MAX;
                }
            }
        }
        
        pq.push({0, {0, 0}}); // Add the top-left cell to the priority queue
        
        while(!pq.empty()) {
            // Get the cell that has the shortest distance from its neighbor
            pip p = pq.top();
            pq.pop();
            auto [d, idx] = p;
            auto [r, c] = idx;
            // If we reach the bottom-right corner of the matrix, d is the value
            // we want
            if(r == m - 1 && c == n - 1) {
                return d;
            }
            
            for(int i = 0; i < 4; ++i) {
                int rr = r + direction[i][0];
                int cc = c + direction[i][1];
                // If the index we try to check is out of bound, we continue to
                // check the next index
                if(rr < 0 || rr >= m || cc < 0 || cc >= n) {
                    continue;
                }
                int d_new = max(d, abs(heights[r][c] - heights[rr][cc]));
                // If the new distance is shorter than the original distance, 
                // update the new distance, and add the vertex back to the 
                // priority queue
                if(d_new < dist[rr][cc]) {
                    dist[rr][cc] = d_new;
                    pq.push({d_new, {rr, cc}});
                }
            }
        }
        
        return 0;
    }
};
