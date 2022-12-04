#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        
        for(char c : s){
            counts[c]++;
        }
        
        sort(s.begin(), s.end(), [&](char a, char b){
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
        });
        
        return s;
    }
};
