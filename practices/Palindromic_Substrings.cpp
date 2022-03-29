#include <string>

using namespace std;

class Solution {
private:
    // input: string s and its length n
    int dynamicProgramming(string& s, int& n) {
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        int counter = 0, i, j;

        // dp[i][j] means whether the substring from i to j is palindromic
        // Case 1: s[i] != s[j], in this case the substring is definitely not palindromic
        // Case 2: s[i] == s[j], this case can be further divided into two subcases
        //      Subcase 1: the distance between i and j is smaller than or euqal to 2, in this case 
        //              the substring is definitely palindromic.
        //      Subcase 2: the distance between i and j is larger than 2, in this case we need to check
        //              whether the substring from i + 1 to j - 1 is palindromic
        for(i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if((s[i] == s[j]) && ((j - i <= 2) || dp[i+1][j-1])) {
                    dp[i][j] = 1;
                    ++counter;
                }
            }
        }

        return counter;
    }

    int countPalindromes(string& s, int l, int r, int& n) {
        int counter = 0;
        while(l >= 0 && r < n) {
            if(s[l] != s[r]) {
                break;
            }
            --l;
            ++r;
            ++counter;
        }
        return counter;
    }

    int expandFromCenter(string& s, int& n) {
        int counter = 0;

        for(int i = 0; i < n; ++i) {
            counter += countPalindromes(s, i, i, n);
            counter += countPalindromes(s, i, i+1, n);
        }

        return counter;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        // return dynamicProgramming(s, n);
        return expandFromCenter(s, n);
    }
};
