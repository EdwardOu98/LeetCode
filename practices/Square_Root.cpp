using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long low = 1, high = x, mid, prod, res;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            prod = mid * mid;
            if(prod == x) {
                return mid;
            }
            else if(prod < x) {
                low = mid + 1;
                res = mid;
            }
            else {
                high = mid-1;
            }
        }
        
        return res;
    }
};
