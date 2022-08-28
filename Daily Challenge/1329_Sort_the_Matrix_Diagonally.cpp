#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = m ? mat[0].size() : 0;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> umap;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                umap[i-j].push(mat[i][j]);
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = umap[i-j].top();
                umap[i-j].pop();
            }
        }
        
        return mat;
    }
};
