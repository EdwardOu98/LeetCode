#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii; // Weight - Destination
    
    void Dijkstra(vector<pii> adj[], int delay[], int start) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, start});
        delay[start] = 0;
        
        while(!pq.empty()) {
            auto [currTime, curr] = pq.top();
            pq.pop();
            
            // If the transmission time to the current node
            // is longer than the one that has been calculated,
            // we skip the current round
            if(currTime > delay[curr]) {
                continue;
            }
            
            // Visit all nodes adjacent to the current node
            for(auto& [time, dest] : adj[curr]) {
                // If we can reach the destination node with a 
                // shorter delay, update the transmission delay
                // for the destinaiton node and add it to the 
                // priority queue
                if(delay[dest] > currTime + time) {
                    delay[dest] = currTime + time;
                    pq.push({delay[dest], dest});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> adj[n+1];
        
        for(vector<int>& time: times) {
            adj[time[0]].push_back({time[2], time[1]});
        }
        
        int delay[n+1];
        for(int i = 0; i <= n; ++i) {
            delay[i] = INT_MAX;
        }
        
        Dijkstra(adj, delay, k);
        
        int res = INT_MIN;
        for(int i = 1; i <= n; ++i) {
            res = max(res, delay[i]);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
