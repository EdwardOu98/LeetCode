#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        
        for(int& a : arr) {
            ++count[a];
        }
        
        int freqs[1000] = {0};
        
        for(auto& [_, f] : count) {
            if(++freqs[f] > 1) {
                return false;
            }
        }
        
        return true;
    }
};
