#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool checkStrings(string& s, string& t) {
        unordered_map<char, char> umap;
        int n = s.length();
        
        for(int i = 0; i < n; ++i) {
            if(umap.count(s[i]) && umap[s[i]] != t[i]) {
                return false;
            }
            umap[s[i]] = t[i];
        }
        
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return checkStrings(s, t) && checkStrings(t, s);
    }
};
