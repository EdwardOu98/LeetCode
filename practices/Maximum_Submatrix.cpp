#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int maxSum = matrix[0][0];
        vector<int> res(4, 0);
        int prefixSum[m+1][n];
        for(int j = 0; j < n; ++j) {
            prefixSum[0][j] = 0;
        }

        // Calculate the prefix sum of the matrix in the verticle direction
        for(int i = 1; i <= m; ++i) {
            for(int j = 0; j < n; ++j) {
                prefixSum[i][j] = prefixSum[i-1][j] + matrix[i-1][j];
            }
        }

        for(int top = 0; top < m; ++top) {
            for(int bottom = top; bottom < m; ++bottom) {
                int arr[n];
                for(int i = 0; i < n; ++i) {
                    arr[i] = prefixSum[bottom+1][i] - prefixSum[top][i];
                }
                int start = 0, sum = arr[0];
                for(int i = 1; i < n; ++i) {
                    if(sum > 0) {
                        sum += arr[i];
                    }
                    else {
                        sum = arr[i];
                        start = i;
                    }

                    if(sum > maxSum) {
                        maxSum = sum;
                        res[0] = top;
                        res[1] = start;
                        res[2] = bottom;
                        res[3] = i;
                    }
                }
            }
        }

        return res;
    }
};
