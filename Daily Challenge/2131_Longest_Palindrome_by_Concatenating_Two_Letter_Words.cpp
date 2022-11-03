#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> umap;
        
        for(string& s : words) {
            ++umap[s];
        }
        
        int res = 0;
        bool central = false; // Whether we have a central word
        
        for(auto& [word, num] : umap) {
            // If the word itself is a palindrome
            if(word[0] == word[1]) {
                // If the word occurred odd times in the input array
                if(num % 2) {
                    // Take one and use it as the 
                    res += num - 1;
                    central = true;
                }
                else {
                    res += num;
                }
            }
            else if(word[0] < word[1] && umap.count({word[1], word[0]})) {
                res += 2 * min(num, umap[{word[1], word[0]}]);
            }
        }
        
        // If we have a central word, add it to the result
        if(central) {
            ++res;
        }
        
        return 2 * res;
    }
};
