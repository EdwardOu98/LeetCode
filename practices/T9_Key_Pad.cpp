#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> res;
        // Map characters to the number on key pad
        int key[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8,
                       9, 9, 9, 9};
        
        // For each word in the array, find their corresponding number combination.
        // If the combination matches with the input number, add the current word
        // to the result array
        for(string& word : words) {
            string s = "";
            for(char& c : word) {
                s += '0' + key[c - 'a'];
            }
            if(s == num) {
                res.push_back(word);
            }
        }

        return res;
    }
};
