#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    int n;

    void dfs(vector<vector<int>>& graph, bool visited[], int vertex) {
        // If the current vertex is the n - 1 node, add the current path
        // to the result array
        if(vertex == n - 1) {
            res.push_back(temp);
            return;
        }

        for(int v : graph[vertex]) {
            // if the current node has not been visited before
            if(!visited[v]) {
                visited[v] = true;
                temp.push_back(v);
                dfs(graph, visited, v);
                temp.pop_back();
                visited[v] = false;
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        bool visited[n];
        memset(visited, false, sizeof(visited));
        visited[0] = true;
        temp.push_back(0);

        for(int vertex : graph[0]) {
            visited[vertex] = true;
            temp.push_back(vertex);
            dfs(graph, visited, vertex);
            temp.pop_back();
            visited[vertex] = false;
        }

        return res;
    }
};
