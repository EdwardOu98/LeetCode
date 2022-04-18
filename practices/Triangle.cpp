#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) {
            return triangle[0][0];
        }
        vector<int> m = triangle[n-1];
        
        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                m[j] = triangle[i][j] + min(m[j], m[j+1]);
            }
        }
        
        return m[0];
    }
};
