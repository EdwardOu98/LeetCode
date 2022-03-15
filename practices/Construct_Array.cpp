#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size(), product = 1;
        vector<int> b(n, 0);

        // 从左向右累乘
        for(int i = 0; i < n; ++i) {
            b[i] = product;
            product *= a[i];
        }

        // 从右向左累乘
        product = 1;
        for(int i = n - 1; i >= 0; --i) {
            b[i] *= product;
            product *= a[i];
        }

        return b;
    }
};
