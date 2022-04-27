#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static const int maxSize = 100001;
    vector<int> adjList[maxSize];
    bool visited[maxSize];
    
    void dfs(int vertex, vector<char>& characters, vector<int>& indices, string& s) {
        // Store the connected vertex and their corresponding characters
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        
        // Mark the current vertex as visited
        visited[vertex] = true;
        
        // Visited the nodes in the vertex's adjacency list
        for(int adj : adjList[vertex]) {
            if(!visited[adj]) {
                dfs(adj, characters, indices, s);
            }
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // Build the adjacency list. Note that the edge is undirected
        for(vector<int>& p : pairs) {
            adjList[p[0]].push_back(p[1]);
            adjList[p[1]].push_back(p[0]);
        }
        
        int n = s.length();
        
        for(int i = 0; i < n; ++i) {
            // If we have not visited the current character with dfs
            if(!visited[i]) {
                vector<char> characters;
                vector<int> indices;
                // Obtain the characters and indices that are connected
                // with the current character through the pairs array
                dfs(i, characters, indices, s);
                
                // Sort the list of characters and indices
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());
                
                // Place the character at the corresponding index
                for(int j = 0; j < characters.size(); ++j) {
                    s[indices[j]] = characters[j]; 
                }
            }
        }
        
        return s;
    }
};
