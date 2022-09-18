#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    static bool comp(int a, int b) {
        return abs(a) < abs(b);
    }
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // If the array contains odd number of elements, then
        // it cannot be a doubled array
        if(changed.size() % 2) {
            return {};
        }
        
        unordered_map<int, int> freq;
        
        for(int& n : changed) {
            ++freq[n];
        }
        
        vector<int> keys;
        
        for(auto& [key, _] : freq) {
            keys.push_back(key);
        }
        
        sort(keys.begin(), keys.end(), comp);
        
        vector<int> res;
        for(int& k : keys) {
            if(freq[k] > freq[2*k]) {
                return {};
            }
            
            for(int i = 0; i < freq[k]; ++i, --freq[2*k]) {
                res.push_back(k);
            }
        }
        
        return res;
    }
};
