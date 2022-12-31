#include <vector>

using namespace std;

class Solution {
private:
    int dfs(vector<vector<int> >& grid, int i, int j, int curr_steps, int& total_steps){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1){
            return 0;
        }
        if(grid[i][j] == 2){
            return curr_steps == total_steps ? 1 : 0;
        }
        
        grid[i][j] = -1;
        ++curr_steps;
        int res = dfs(grid, i + 1, j, curr_steps, total_steps) + dfs(grid, i - 1, j, curr_steps, total_steps) + dfs(grid, i, j + 1, curr_steps, total_steps) + dfs(grid, i, j - 1, curr_steps, total_steps);
        grid[i][j] = 0;
        return res;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i1 = 0, j1 = 0, total_steps = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    i1 = i;
                    j1 = j;
                }
                if(grid[i][j] != -1){
                    ++total_steps;
                }
            }
        }
        return dfs(grid, i1, j1, 1, total_steps);
    }
};
