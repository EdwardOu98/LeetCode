#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> valMap = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
                                            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
                                            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string res;
        
        for(int i = 0; num != 0; ++i) {
            while(num >= valMap[i].first) {
                res += valMap[i].second;
                num -= valMap[i].first;
            }
        }
        
        return res;
    }
};
