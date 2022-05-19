#include <vector>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0) {
            return {};
        }
        if(shorter == longer) {
            return {shorter * k};
        }

        vector<int> res;
        int len = shorter * k; // The shortest case: k shorter boards
        res.push_back(len);
        for(int i = k; i > 0; --i) {
            // Each time we remove 1 shorter board and add a longer board
            // until all of the shorter boards are replaced by longer boards
            len = len - shorter + longer;
            res.push_back(len);
        }

        return res;
    }
};
