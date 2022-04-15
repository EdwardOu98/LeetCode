#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        // If input array is empty or maxWidth is 0, return an array 
        // that contains only an empty string
        if(n == 0 || maxWidth == 0) {
            return {""};
        }
        
        int i, j, k, l; // i - index of the first string for a new array
                        // j - number of strings/spaces in the new array
                        // k - length of all strings in the new array
                        // l - index offset of strings in the new array
        vector<string> res;
        
        for(i = 0; i < n; i += j) {
            k = 0;
            // i + j need to be smaller than or equal to n, and k + words[i+j].size() need 
            // to be smaller than maxWidth - j. As j is the number of strings in the current 
            // array, and this number is also the number of spaces in the generated string 
            // (one word corresponds to one space)
            for(j = 0; (i + j < n) && (k + words[i + j].size() <= maxWidth - j); ++j) {
                k += words[i + j].size();
            }
            
            string s = words[i];
            for(l = 0; l < j - 1; ++l) {
                // If the current generated string is the last one, it satisfy the condition
                // that i + j >= n. In this case, the string need to be left-justified and 
                // we have one space after each word
                if(i + j >= n) {
                    s += " ";
                }
                // In other cases, the generated string needs to be fully-justified. And the
                // number of spaces between each word is (maxWidth - k) / (j - 1) + (l < 
                // ((maxWidth - k) % (j - 1))). In the first half of this formula, maxWidth
                // - k represents the total number of spaces we need to have in this generated
                // string, j - 1 is the number of spaces if we have j words. (maxWidth - k) / 
                // (j - 1) is the minimum number of space characters we need to place between
                // each word. In the second half of the formula, (maxWidth - k) % (j - 1) is
                // the number of extra spaces after we evenly distributed the spaces between
                // words. If l is less than this number, then we add an extra space character
                // to the sequence of spaces before the current word
                else {
                    int spaceLen = (maxWidth - k) / (j - 1) + (l < ((maxWidth - k) % (j - 1)));
                    s += string(spaceLen, ' ');
                }
                s += words[i + l + 1];
            }
            // Add extra spaces to the end of the string if its length is less that maxWidth
            s += string(maxWidth - s.length(), ' ');
            res.push_back(s);
        }
        
        return res;
    }
};
