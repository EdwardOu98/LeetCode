#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        string colors = "RYBG";
        vector<int> res(2);
        unordered_map<char, int> s, g;

        for(int i = 0; i < 4; ++i) {
            // If the character on the same position matches, 
            // increment the matching count
            if(solution[i] == guess[i]) {
                ++res[0];
            }
            // Otherwise increment the character count
            else {
                ++s[solution[i]];
                ++g[guess[i]];
            }
        }

        // For each of the 4 characters, find the minimum
        // number of occurences in both strings and add it
        // to the non-matching count
        for(char& c : colors) {
            res[1] += min(s[c], g[c]);
        }

        return res;
    }
};
