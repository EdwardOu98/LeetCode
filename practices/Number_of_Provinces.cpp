#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    void dfs(vector<vector<int>>& isConnected, bool visited[], int idx) {
        visited[idx] = true;
        for(int j = 0; j < n; ++j) {
            if(idx != j && isConnected[idx][j] && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        if(n == 0) {
            return 0;
        }

        int res = 0;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; ++i) {
            // If we find a new city, increment
            // the province count and use dfs to
            // find all cities connected to this
            // one
            if(!visited[i]) {
                ++res;
                dfs(isConnected, visited, i);
            }
        }

        return res;
    }
};
