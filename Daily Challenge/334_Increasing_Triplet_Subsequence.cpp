#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for(int n : nums) {
            // If the current number is less than or equal to c1,
            // then update c1
            if(n <= c1) {
                c1 = n;
            }
            // If the current number is greater than c1 and less than
            // or equal to c2, update c2
            else if(n <= c2) {
                c2 = n;
            }
            // If the current number is greater than both c1 and c2, 
            // return true
            else {
                return true;
            }
        }
        
        return false;
    }
};
