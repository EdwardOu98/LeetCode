#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    int find(int group[], int x) {
        while(group[x] != x) {
            x = group[x];
        }
        return x;
    }

    bool merge(int group[], int x, int y) {
        int gx = find(group, x);
        int gy = find(group, y);
        if(gx != gy) {
            group[gy] = gx;
            return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int group[n + 1];
        iota(group, group + n + 1, 0);

        for(vector<int>& e : edges) {
            // If the two vertices on this edge is in the same group,
            // then this is the redundant edge we need to find
            if(!merge(group, e[0], e[1])) {
                return e;
            }
        }

        return {};
    }
};
