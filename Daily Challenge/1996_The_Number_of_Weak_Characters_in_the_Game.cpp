#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        
        return a[0] < b[0];
    }
public:
    // properties[i][0] = attack_i, properties[i][1] = defense_i
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        int maxDefense = INT_MIN;
        int res = 0;
        
        for(int i = properties.size() - 1; i >= 0; --i) {
            if(properties[i][1] < maxDefense) {
                ++res;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
            
        return res;
    }
};
