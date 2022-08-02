#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int count = 0, c = n - 1;
        
        for(int r = 0; r < m; ++r) {
            while(c >= 0 && matrix[r][c] > x) {
                --c;
            }
            count += (c + 1);
        }
        
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1], res = -1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            if(countLessOrEqual(matrix, mid) >= k) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return res;
    }
};
