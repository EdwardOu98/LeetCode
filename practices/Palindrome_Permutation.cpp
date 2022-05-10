#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool counterSolution(string s) {
        int counter[128] = {0};

        for(char& c : s) {
            ++counter[c];
        }

        int oddCount = 0;
        for(int i = 0; i < 128; ++i) {
            if(counter[i] % 2) {
                ++oddCount;
            }
        }

        return oddCount <= 1;
    }
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> uset;

        for(char& c : s) {
            if(uset.count(c)) {
                uset.erase(c);
            }
            else {
                uset.insert(c);
            }
        }

        return uset.size() <= 1;
    }
};
