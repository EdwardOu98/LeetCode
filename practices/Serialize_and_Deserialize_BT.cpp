#include <string>
#include <vector>
#include <queue>

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
    // Both serialization and deserialization uses level order traversal
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "";
        }
        string data;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // if current node is not null, put its value in
            // data and push its left and right child into the 
            // queue
            if(curr) {
                data.append(to_string(curr->val) + " ");
                q.push(curr->left);
                q.push(curr->right);
            }
            else {
                data.append("null ");
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return nullptr;
        }
        int i = 0, j = 0, n = data.length();
        vector<TreeNode*> nodes;
        while(j < n) {
            if(data[j] == ' '){
                // extract a node value from input data
                string val = data.substr(i, j - i);
                if(val == "null") {
                    nodes.push_back(nullptr);
                }
                else {
                    nodes.push_back(new TreeNode(stoi(val)));
                }
                i = j + 1;
            }
            ++j;
        }

        // pos indicates the index of the children of the cirrent node
        int pos = 1;
        n = nodes.size();
        for(i = 0; i < n; ++i) {
            if(nodes[i]) {
                nodes[i]->left = nodes[pos++];
                nodes[i]->right = nodes[pos++];
            }
        }

        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
