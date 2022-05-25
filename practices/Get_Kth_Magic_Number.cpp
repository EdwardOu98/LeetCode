using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        int res[k];
        res[0] = 1;
        int n3 = 0, n5 = 0, n7 = 0;

        for(int i = 1; i < k; ++i) {
            int a = 3 * res[n3], b = 5 * res[n5], c = 7 * res[n7];
            res[i] = min({a, b, c});

            if(res[i] == a) {
                ++n3;
            }
            if(res[i] == b) {
                ++n5;
            }
            if(res[i] == c) {
                ++n7;
            }
        }

        return res[k-1];
    }
};
