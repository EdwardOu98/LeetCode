#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii;

    const int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
                           {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int m, n;

    int dfs(vector<vector<int>>& land, int x, int y) {
        // If the current index is out of bound or the current grid is not
        // water, return 0
        if(x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) {
            return 0;
        }

        int res = 1;
        // Mark the current grid as -1 to prevent revisiting the same grid
        land[x][y] = -1;
        for(int i = 0; i < 8; ++i) {
            // Visit the next grid
            res += dfs(land, x + dir[i][0], y + dir[i][1]);
        }

        return res;
    }

    int bfs(vector<vector<int>>& land, int i, int j) {
        queue<pii> q;
        q.push({i, j});
        land[i][j] = -1;
        int res = 1;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 8; ++i) {
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx < 0 || xx >= m || yy < 0 || yy >= n || land[xx][yy] != 0) {
                    continue;
                }
                ++res;
                land[xx][yy] = -1;
                q.push({xx, yy});
            }
        }

        return res;
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        m = land.size();
        n = m ? land[0].size() : 0;
        vector<int> res;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(land[i][j] == 0) {
                    res.push_back(dfs(land, i, j));
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};
