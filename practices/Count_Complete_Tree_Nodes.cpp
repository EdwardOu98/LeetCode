#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Use level order traversal to find the total number of nodes
    // Time complexity: O(n)
    int levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(root->left) {
                q.push(root->left);
            }
            if(root->right) {
                q.push(root->right);
            }
            ++count;
        }
            
        return count;
    }
    
    // Calculate the number of nodes based on the height of tree
    // Time complexity: O(logn * logn)
    int countNumNodes(TreeNode* root) {
        int heightl = 0, heightr = 0;
        TreeNode* left = root, *right = root;
        
        while(left) {
            ++heightl;
            left = left->left;
        }
        
        while(right) {
            ++heightr;
            right = right->right;
        }
        
        // If the left and right tree has the same height, 
        // it means that the binary tree is full. For a full
        // binary tree, the number of nodes are 2^h - 1, where
        // h is the height of the tree
        if(heightl == heightr) {
            return pow(2, heightl) - 1;
        }
        
        return 1 + countNumNodes(root->left) + countNumNodes(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        // return levelOrder(root);
        return countNumNodes(root);
    }
};
