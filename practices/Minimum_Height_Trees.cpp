#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // corner case
        if(n == 1) {
            return {0};
        }
        
        // Build the adjacency list
        vector<unordered_set<int>> adjList(n);
        for(vector<int>& e : edges) {
            adjList[e[0]].insert(e[1]);
            adjList[e[1]].insert(e[0]);
        }
        
        // Add the leaf nodes to the current array
        vector<int> curr;
        for(int i = 0; i < n; ++i) {
            if(adjList[i].size() == 1) {
                curr.push_back(i);
            }
        }
        
        // Continuously remove leaf nodes until the last one/two nodes
        while(true) {
            vector<int> next;
            for(int node : curr) {
                // For each leaf node in the current array, remove it from
                // its neighbor's adjacency list. If the neighbor node's 
                // adjacency list becomes size 1, add it to the next array
                for(int neighbor : adjList[node]) {
                    adjList[neighbor].erase(node);
                    if(adjList[neighbor].size() == 1) {
                        next.push_back(neighbor);
                    }
                }
            }
            // If the next array is empty, which means we have the last
            // one/two leaf nodes, leave the loop
            if(next.empty()) {
                break;
            }
            curr = next;
        }
        return curr;
    }
};
