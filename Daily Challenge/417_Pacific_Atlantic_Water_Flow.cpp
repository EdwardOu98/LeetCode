#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        
        visited[r][c] = true;
        
        // Up
        if(r-1 >= 0 && !visited[r-1][c] && heights[r-1][c] >= heights[r][c]) {
            dfs(heights, visited, r-1, c);
        }
        // Down
        if(r+1 < m && !visited[r+1][c] && heights[r+1][c] >= heights[r][c]) {
            dfs(heights, visited, r+1, c);
        }
        // Left
        if(c-1 >= 0 && !visited[r][c-1] && heights[r][c-1] >= heights[r][c]) {
            dfs(heights, visited, r, c-1);
        }
        // Right
        if(c+1 < n && !visited[r][c+1] && heights[r][c+1] >= heights[r][c]) {
            dfs(heights, visited, r, c+1);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) {
            return {};
        }
        
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for(int r = 0; r < m; ++r) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, n - 1);
        }
        
        for(int c = 0; c < n; ++c) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, m - 1, c);
        }
        
        vector<vector<int>> res;
        
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        
        return res;
    }
};
