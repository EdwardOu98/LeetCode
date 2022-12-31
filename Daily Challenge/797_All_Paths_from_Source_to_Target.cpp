#include <vector>

using namespace std;

class Solution {
private: 
    void dfs(vector<vector<int> >& g, vector<vector<int> >& res, vector<int>& p, int cur){
        p.push_back(cur);
        if(cur == g.size() - 1){
            res.push_back(p);
        }
        else{
            for(auto& e : g[cur]){
                dfs(g, res, p, e);
            }
        }
        p.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > res;
        vector<int> p;
        dfs(graph, res, p, 0);
        return res;
    }
};
