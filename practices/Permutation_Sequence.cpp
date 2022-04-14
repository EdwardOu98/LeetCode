#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = ""; // Contains all the numbers to generate permutations
        int factorial = 1; // Number of peermutations
        for(int i = 1; i <= n; ++i) {
            s.push_back('0' + i); // s will then contain '1''2''3'...'n'
            factorial *= i;
        }
        
        --k;
        
        for(int i = 0; i < n; ++i) {
            factorial /= n - i;
            int j = i + k / factorial; // Calculate index of number to put at s[i];
            char c = s[j];
            for(; j > i; --j) {
                s[j] = s[j-1];
            }
            k %= factorial;
            s[i] = c;
        }
        
        return s;
    }
};
