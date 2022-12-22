#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<unordered_set<int> > tree;
    vector<int> res, count;
    void dfs(int root, int child){
        for(const auto& i : tree[root]){
            if(i == child){
                continue;
            }
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }
    
    void dfs1(int root, int child){
        for(const auto& i : tree[root]){
            if(i == child){
                continue;
            }
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs1(i, root);
        }
    }
  
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.assign(n, 0);
        count.assign(n, 1);
        for(const auto& e : edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs1(0, -1);
        return res;
    }
};
