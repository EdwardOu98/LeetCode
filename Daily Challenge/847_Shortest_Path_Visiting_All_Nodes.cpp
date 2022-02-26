#include <vector>
#include <queue>

using namespace std;

class Solution {
// Using BFS to find the shortest path
// from one node to all others, except
// that we need to do BFS on all nodes
private:
    class Tuple {
        public:
        int node;
        int cost;
        int mask;
        
        Tuple(int _node, int _cost, int _mask) {
            node = _node;
            cost = _cost;
            mask = _mask;
        }
    };
    
    bool visited[1 << 12][12];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) {
            return 0;
        }
        
        queue<Tuple> q;
        
        for(int i = 0; i < n; ++i) {
            int tmp = 1 << i;
            Tuple t(i, 1, tmp);
            q.push(t);
            visited[1 << i][i] = true;
        }
        
        while(!q.empty()) {
            Tuple curr = q.front();
            q.pop();
            
            if(curr.mask == ((1 << n) - 1)) {
                return curr.cost - 1;
            }
            
            for(auto& child : graph[curr.node]) {
                int bitmask = curr.mask;
                bitmask |= (1 << child);
                
                Tuple t(child, curr.cost + 1, bitmask);
                if(!visited[bitmask][child]) {
                    q.push(t);
                    visited[bitmask][child] = true;
                }
            }
        }
        
        return -1;
    }
};
