#include <utility>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii;

    // In the clockwise direction, right, down, left, up
    const char flags[4] = {'R', 'D', 'L', 'U'};
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<string> printKMoves(int K) {
        map<pii, char> m; // Record the color of a certain grid
        int flag = 0; // Record the heading of the the ant
        int x = 0, y = 0; // Record the location of the ant
        int l = 0, r = 0, u = 0, d = 0; // Record the maximum displacement in
                                        // 4 directions
        
        while(K--) {
            // If the ant is currently on a white grid
            if(!m.count({x, y}) || m[{x, y}] == '_') {
                m[{x, y}] = 'X'; // Flip the grid to black
                flag = (flag + 1) % 4; // Turn the ant in clockwise direction
                x += dir[flag][0];
                y += dir[flag][1];
            }
            // If the ant is currently on a black grid
            else {
                m[{x, y}] = '_'; // Flip the grid to white
                flag = (flag == 0) ? 3 : flag - 1; // Turn the ant in counter-clockwise direction
                x += dir[flag][0];
                y += dir[flag][1];
            }

            // Update the maximum displacements in the 4 directions
            l = min(l, y);
            r = max(r, y);
            u = min(u, x);
            d = max(d, x);
        }

        // Construct the matrix with all grids the ant has pass through
        vector<string> res(d - u + 1, string(r - l + 1, '_'));
        for(auto& [pos, c] : m) {
            // Mark the color of each grid
            auto [i, j] = pos;
            res[i - u][j - l] = c;
        }

        // Mark the final heading of the ant
        res[x - u][y - l] = flags[flag];

        return res;
    }
};
