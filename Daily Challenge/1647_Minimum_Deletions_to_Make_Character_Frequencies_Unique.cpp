#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int frequency[26] = {0}; // Frequency of each character in string s
        int deleteCount = 0; // Number of characters deleted
        
        // Record the frequency of each character
        for(char& c : s) {
            ++frequency[c - 'a'];
        }
        
        unordered_set<int> visited;
        
        for(int i = 0; i < 26; ++i) {
            // Delete one of the current character when and only when
            // its frequency is greater than 0 and the frequency has
            // been visited before
            while(frequency[i] > 0 && visited.count(frequency[i])) {
                --frequency[i];
                ++deleteCount;
            }
            // Add the frequency of the current character into the visited
            // hash set
            visited.insert(frequency[i]);
        }
        
        // Return the total number of characters deleted
        return deleteCount;
    }
};
