#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<int, int> f;
    int island = 0;
    
    int find(int x) {
        if(!f.count(x)) {
            f[x] = x;
            ++island;
        }
        
        while(x != f[x]) {
            x = f[x];
        }
        
        return f[x];
    }
    
    void Union(int x, int y) {
        x = find(x); 
        y = find(y);
        
        if(x != y) {
            f[x] = y;
            --island;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        for(auto& s : stones) {
            Union(s[0], ~s[1]);
        }
        
        return stones.size() - island;
    }
};
