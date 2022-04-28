#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // There are 3 status for each node: unpainted (-1), color1 (0), color2 (1). If the 
    // If two adjacent nodes are painted as the same color, the graph is not bipartite
    bool paintGrid(vector<vector<int>>& graph, int colors[], int color, int vertex) {
        colors[vertex] = color; // Paint the current grid with color
        queue<int> q;
        q.push(vertex);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            // Check the adjacency list of u
            for(int v : graph[u]) {
                // If the vertex has not been visited before, change its color and
                // add it to the queue
                if(colors[v] == -1) {
                    colors[v] = 1 - colors[u]; // If u's color is 0, v will be 1;
                                             // If u's color is 1, v will be 0;
                    q.push(v);
                }
                else {
                    // If v has the same color as u, return false
                    if(colors[v] == colors[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int colors[n];
        // Initialize all nodes as unpainted (-1)
        for(int i = 0; i < n; ++i) {
            colors[i] = -1;
        }

        for(int i = 0; i < n; ++i) {
            if(colors[i] == -1) {
                if(!paintGrid(graph, colors, 0, i)){
                    return false;
                }
            }
        }
        return true;
    }
};
