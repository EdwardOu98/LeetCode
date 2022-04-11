#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<char, int> umap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, 
                                     {'D', 500}, {'M', 1000}};
public:
    // Start converting from the back of the string
    int romanToInt(string s) {
        // The initial result is the numbre corresponding to the last character in the string
        int res = umap[s.back()];
        
        // Iterate from the second to last character to the first character in the string
        for(int i = s.length() - 2; i >= 0; --i) {
            // If the number corresponding to the current character is smaller than that
            // to the previous character, we need to substract this number from the result
            if(umap[s[i]] < umap[s[i+1]]) {
                res -= umap[s[i]];
            }
            // Otherwise we simply add the number to the result
            else {
                res += umap[s[i]];
            }
        }
        return res;
    }
};
