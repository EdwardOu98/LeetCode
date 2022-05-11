#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<int> adj[n];
        // Construct the adjacency list
        for(vector<int>& e : graph) {
            adj[e[0]].push_back(e[1]);
        }

        // Because it's possible to have cycles and parallel edeges in the graph, we use
        // a visited array to keep track of visited nodes
        bool visited[n];
        memset(visited, false, sizeof(visited));

        // Use BFS to check whether there exists a path from start to target
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int& v : adj[u]) {
                if(!visited[v]) {
                    if(v == target) {
                        return true;
                    }
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }
};
