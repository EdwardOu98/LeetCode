#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Use an ordered multiset to store the destinations that can be
    // reached from the key airport so that the destinations are
    // automatically sorted in lexical order. 
    unordered_map<string, multiset<string>> targets; // Starting airport - {Destination Airports}
    vector<string> route; // The path that pass through all airports
    
    void dfs(string start) {
        while(!targets[start].empty()) {
            // Get the next destination
            string next = *targets[start].begin();
            // Remove the next destination from the multiset to represent that we have used
            // the ticket
            targets[start].erase(targets[start].begin());
            // Visit the next destination
            dfs(next);
        }
        // After using all the tickets in this airport, add the current airport to the route
        route.push_back(start);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string>& ticket : tickets) {
            targets[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        
        // Reverse the route array
        reverse(route.begin(), route.end());
        
        return route;
    }
};
