#include <vector>

using namespace std;

class Solution {
private:
    vector<int> count(int n) {
        vector<int> res(10, 0);
        
        while(n > 0) {
            ++res[n % 10];
            n /= 10;
        }
        
        return res;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digits = count(n);
        
        for(int i = 0; i < 30; ++i) {
            if(digits == count(1 << i)) {
                return true;
            }
        }
        
        return false;
    }
};
