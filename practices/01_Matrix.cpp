#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // Initialize the dist matrix with INT_MAX - 1e5 to prevent
        // overflow in later calculations
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX - 1e5));

        // Because the minimum distance from the current cell to the nearest
        // 0 can be in all four directions (top, bottom, left, and right), we
        // need to consider all of them. Thus, we need to first iterate the matrix
        // starting from the top-left and check the top and left direction. Then we
        // iterate the matrix again from the bottom-right to check the bottom and 
        // right direction.
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // If the current cell of the matrix is 0, the corresponding cell
                // in the dist matrix is also 0
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                }
                else {
                    // Check the top
                    if(i > 0) {
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    }
                    // Check the left
                    if(j > 0) {
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                    }
                }
            }
        }

        // Iterate from the bottom-right direction
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                // Check bottom
                if(i < m - 1) {
                    dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                }
                // Check right
                if(j < n - 1) {
                    dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
                }
            }
        }

        return dist;
    }
};
