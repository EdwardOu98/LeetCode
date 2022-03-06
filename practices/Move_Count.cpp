#include <vector>

using namespace std;

class Solution {
private:
    int dfs(int x, int y, int m, int n, int k, vector<vector<int>>& visited) {
        if(x < 0 || x >= m || y < 0 || y >= n || (x / 10 + x % 10 + y / 10 + y % 10) > k || visited[x][y]) {
            return 0;
        }
        visited[x][y] = 1;
        return 1 + dfs(x - 1, y, m, n, k, visited)
                + dfs(x + 1, y, m, n, k, visited)
                + dfs(x, y - 1, m, n, k, visited)
                + dfs(x, y + 1, m, n, k, visited);
    }
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector<int>(n, 0));

        return dfs(0, 0, m, n, k, visited);
    }
};
