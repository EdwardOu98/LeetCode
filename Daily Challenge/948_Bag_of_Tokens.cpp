#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        int points = 0, res = 0;
        
        while((low <= high) && (power >= tokens[low] || points > 0)) {
            while(low <= high && power >= tokens[low]) {
                power -= tokens[low++];
                ++points;
            }
            
            res = max(res, points);
            if(low <= high && points > 0) {
                power += tokens[high--];
                --points;
            }
        }
        
        return res;
    }
};
