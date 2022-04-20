#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        
        // If the node has not been cloned, clone it
        // and put it into the map. For each of its 
        // neighbors, we make a copy and add it to the 
        // node's copy's neighbors list
        if(!copies.count(node)) {
            copies[node] = new Node(node->val);
            for(Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        
        return copies[node];
    }
};
