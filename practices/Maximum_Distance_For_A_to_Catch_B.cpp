#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void bfs(vector<int>& dist, bool visited[], int start) {

    queue<int> q;
    q.push(start);

    dist[start] = 0;
    visited[start] = true;

    int steps = 0;
    while(!q.empty()) {
        int m = q.size();
        ++steps;
        for(int i = 0; i < m; ++i) {
            int u = q.front();
            q.pop();
            for(int& v : graph[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dist[v] = steps;
                    q.push(v);
                }
            }
        }
    }
}

int main(void) {
    int n, x, y; // n - number of nodes
                 // x - starting position of A
                 // y - starting position of B

    cin >> n >> x >> y;
    graph.resize(n+1);

    int u, v; // Two vertices connected by the edge uv
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distA(n+1);
    vector<int> distB(n+1);
    bool visited[n+1];
    
    // Find the minimum distance from x to all other nodes
    memset(visited, false, sizeof(visited));
    bfs(distA, visited, x);
    // Find the minimum distance from y to all other nodes
    memset(visited, false, sizeof(visited));
    bfs(distB, visited, y);


    int res = 0;
    // For A to catach B, the maximum time it takes depends
    // on the distance from x and y to all other nodes. If
    // distB[i] is smaller than distA[i], that means it takes
    // more time for A to reach this vertex than that for B. 
    // Thus, the maximum distance for A to catch B depends on
    // the nodes that are further to reach for A. 
    for(int i = 1; i <= n; ++i) {
        if(distA[i] > distB[i]) {
            res = max(res, distA[i]);
        }
    }

    cout << res << endl;

    return 0;
}
