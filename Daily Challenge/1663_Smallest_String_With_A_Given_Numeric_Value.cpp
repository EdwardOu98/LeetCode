#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');         // Build an initial string of length n with all a's
        k -= n;                     // Minus n from k, as we have used n a's for the string and 
                                    // a has value of 1
        
        int i = n - 1;              // Iterate the string from the end to the beginning
        while(k > 0) {
            int temp = min(k, 25);  // Greedily add the largest possible character to the end of the string
            res[i] += temp;
            k -= temp;
            --i;
        }
        
        return res;
    }
};
