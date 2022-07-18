#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int count = 0;
        
        // Calculate the prefix sum of each row
        for(int i = 0; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        unordered_map<int, int> memo;
        
        // For each combination of two columns, sum up the
        // prefix sum of the rows in between the two columns
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                memo = {{0, 1}};
                int curr = 0;
                for(int k = 0; k < m; ++k) {
                    curr += matrix[k][j] - ((i > 0) ? matrix[k][i-1] : 0);
                    if(memo.count(curr - target)) {
                        count += memo[curr - target];
                    }
                    ++memo[curr];
                }
            }
        }
        
        return count;
    }
};
