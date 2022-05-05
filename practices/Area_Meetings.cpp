#include <iostream>
#include <vector>

using namespace std;

static const int MOD = 1e9 + 7;
int k; // rank difference limit
int lower; // Lower bound of valid area
int upper; // upper bound of valid area
int id; // Node id when starting the dfs scan

vector<vector<int>> graph;
vector<int> ranks;
vector<bool> visited;

long dfs(int u) {
    // If the current node is out of bound, return to the previous level
    if(ranks[u] < lower || ranks[u] > upper) {
        return 0;
    }
    // If the current path has been calculated before, return to the previous level
    if(ranks[u] == lower && u < id) {
        return 0;
    }

    long res = 1;
    visited[u] = true;
    for(int& v : graph[u]) {
        // If the node had been visited before, continue to the next round
        if(visited[v]) {
            continue;
        }
        res *= dfs(v) + 1; // + 1 means not choosing the current area is also
                           // an option. This line is equivalent to res = 
                           // res + res * dfs, which includes all possible 
                           // combinations up to the current node plus
                           // all possible combinations if we continue
                           // to explore in lower levels
        res %= MOD; // Make sure the result remains in range
    }
    visited[u] = false;
    return res;
}

int main(void) {
    int n; // number of areas;
    cin >> n >> k;

    graph.resize(n);
    ranks.resize(n);
    visited.resize(n, false);
    int a, b;
    // Get the graph
    for(int i = 1; i < n; ++i) {
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    // Get the ranks of representatives
    for(int i = 0; i < n; ++i) {
        cin >> ranks[i];
    }

    long res = 0;
    for(int i = 0; i < n; ++i) {
        visited[i] = true;
        lower = ranks[i];
        upper = ranks[i] + k;
        id = i;
        res += dfs(i);
        res %= MOD;
        visited[i] = false;
    }

    cout << res << endl;

    return 0;
}
