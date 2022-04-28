#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int m = secret.length();
        if(m != guess.length()) {
            return "0A0B";
        }
        
        int bulls = 0, cows = 0;
        int s[10] = {0}, g[10] = {0}; // Record the number of each digit
                                      // in secret and guess when the
                                      // current digit doesn't match
        
        for(int i = 0; i < m; ++i) {
            // If the current digit matches, increment bull
            if(secret[i] == guess[i]) {
                ++bulls;
            }
            // If they doesn't match, increment the digit counter
            else {
                ++s[secret[i] - '0'];
                ++g[guess[i] - '0'];
            }
        }
        
        // Calculate the "cows", which are digits in the secret
        // number but they are not in the right position
        for(int i = 0; i < 10; ++i) {
            cows += min(s[i], g[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
