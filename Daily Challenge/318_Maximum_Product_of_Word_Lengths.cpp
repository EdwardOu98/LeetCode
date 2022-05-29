#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(); // length of input array
        int b[n]; // Use a 32-bit binary number to record letters in each word
        memset(b, 0, sizeof(b));
        
        for(int i = 0; i < n; ++i) {
            // For each character in each word, mark the corresponding bit as 1
            for(char& c : words[i]) {
                b[i] |= (1 << (c - 'a'));
            }
        }
        
        int maxProd = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                // For the words in the input array, if they don't have common characters, 
                // their binary representation's bit-wise and result should be 0
                if((b[i] & b[j]) == 0) {
                    maxProd = max(maxProd, (int) words[i].length() * (int) words[j].length());
                }
            }
        }
        
        return maxProd;
    }
};
