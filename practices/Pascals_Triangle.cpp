#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for(int i = 1; i <= numRows; ++i) {
            vector<int> temp(i, 1);
            if(i > 2) {
                for(int j = 1; j < i - 1; ++j) {
                    temp[j] = res.back()[j-1] + res.back()[j];
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
