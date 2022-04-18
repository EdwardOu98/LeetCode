#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // For the ith row, it contains i elements
        vector<int> res(rowIndex + 1, 0);
        // The first element is always 1
        res[0] = 1;
        
        // Starts from row index 1 until rowIndex
        for(int i = 1; i <= rowIndex; ++i) {
            // For each row, we fill it starting from
            // the back of the row. 
            for(int j = i; j > 0; --j) {
                res[j] = res[j] + res[j-1];
            }
        }
        
        return res;
    }
};
