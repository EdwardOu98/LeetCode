#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool sorting(string s1, string s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
public:
    bool CheckPermutation(string s1, string s2) {
        int n = s1.length();
        if(n != s2.length()) {
            return false;
        }
        int counter1[26] = {0};
        int counter2[26] = {0};
        for(int i = 0; i < n; ++i) {
            ++counter1[s1[i] - 'a'];
            ++counter2[s2[i] - 'a'];
        }

        for(int i = 0; i < 26; ++i) {
            if(counter1[i] != counter2[i]) {
                return false;
            }
        }
        return true;
    }
};
