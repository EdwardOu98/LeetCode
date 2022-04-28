#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // If the tree is empty, return a "#"
        if(!root) {
            return "#";
        }
        
        queue<TreeNode*> q;
        q.push(root);
        string data;
        
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            // If the current node is not null
            if(temp) {
                // Add a space to separate the current node
                // with the previous node
                data += " " + to_string(temp->val);
                // Add the left and right child of the current node
                // to the queue
                q.push(temp->left);
                q.push(temp->right);
            }
            else {
                // If the current node is null, add a "#"
                data += " #";
            }
        }
        
        // Because the data string contains a leading space, we will get rid
        // of the leading space and use the res as the return value
        return data.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") {
            return nullptr;
        }
        
        vector<TreeNode*> nodes;
        stringstream ss(data);
        string str;
        
        while(getline(ss, str, ' ')) {
            // If the current string is "#", it means we
            // have a NULL node
            if(str == "#") {
                nodes.push_back(nullptr);
            }
            // Otherwise, create a new node with the value
            // of the string
            else {
                nodes.push_back(new TreeNode(stoi(str)));
            }
        }
        
        int pos = 1; // Indicate the position of the child nodes
        int n = nodes.size();
        
        for(int i = 0; i < n; ++i) {
            if(nodes[i]) {
                nodes[i]->left = nodes[pos++];
                nodes[i]->right = nodes[pos++];
            }
        }
        
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
