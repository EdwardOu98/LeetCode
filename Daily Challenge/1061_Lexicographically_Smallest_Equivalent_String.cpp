#include <vector>
#include <string>

using namespace std;

class Solution {
private:

    void Union(vector<int>& m, int c1, int c2) {
        int p1 = find(m, c1), p2 = find(m, c2);
        if(p1 != p2) {
            m[max(p1, p2)] = min(p1, p2);
        }
    }

    int find(vector<int>& m, int c) {
        if(m[c] == -1) {
            return c;
        }

        return m[c] = find(m, m[c]);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> m(26 ,-1);
        for(int i = 0; i < s1.length(); ++i) {
            Union(m, s1[i] - 'a', s2[i] - 'a');
        }

        for(int i = 0; i < baseStr.length(); ++i) {
            baseStr[i] = find(m, baseStr[i] - 'a') + 'a';
        }

        return baseStr;
    }
};
