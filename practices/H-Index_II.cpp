#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), l = 0, r = n - 1, mid;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(n - mid > citations[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return n - l;
    }
};
