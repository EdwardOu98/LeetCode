#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> adj; // Adjacency list
    vector<vector<int>> res;
    vector<int> disc; // Discovery time of each node
    vector<int> low; // lowest future node
    int time = 1; // Use 1 as the initial value of time so that we can use either
                  // disc or low as the visited array
    
    void dfs(int prev, int curr) {
        disc[curr] = low[curr] = time++;
        for(int& next : adj[curr]) {
            // If we havn't visited the node before
            if(disc[next] == 0) {
                dfs(curr, next);
                low[curr] = min(low[curr], low[next]);
            }
            else if(next != prev) {
                low[curr] = min(low[curr], disc[next]);
            }
            if(low[next] > disc[curr]) {
                res.push_back({curr, next});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc.resize(n, 0);
        low.resize(n, 0);
        adj.resize(n);
        for(auto& con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        
        dfs(-1, 0);
        
        return res;
    }
};
