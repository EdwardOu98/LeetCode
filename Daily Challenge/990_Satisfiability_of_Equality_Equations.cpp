#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int parents[26];
    
    int findParent(int p) {
        if(parents[p] == -1) {
            return p;
        }
        
        return parents[p] = findParent(parents[p]);
    }
    
    void unionNode(int a, int b) {
        int p1 = findParent(a);
        int p2 = findParent(b);
        if(p1 != p2) {
            parents[p1] = p2;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; ++i) {
            parents[i] = -1;
        }
        
        for(auto e : equations) {
            if(e[1] == '=') {
                unionNode(e[0] - 'a', e[3] - 'a');
            }
        }
        
        for(auto e : equations) {
            if((e[1] == '!') && findParent(e[0] - 'a') == findParent(e[3] - 'a')) {
                return false;
            }
        }
        
        return true;
    }
};
