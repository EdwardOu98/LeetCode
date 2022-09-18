#include <unordered_map>

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
    int count = 0;
    unordered_map<int, int> freq;
    
    void buildPathAndCount (TreeNode* root) {
        if(!root) {
            return;
        }
        
        ++freq[root->val];
        if(!root->left && !root->right) {
            int oddFreqs = 0; // Number of node values with odd frequency
            
            for(auto& [_, f] : freq) {
                if(f % 2 == 1) {
                    ++oddFreqs;
                }
            }
            
            if(oddFreqs < 2) {
                ++count;
            }
        }
        
        if(root->left) {
            buildPathAndCount(root->left);
        }
        
        if(root->right) {
            buildPathAndCount(root->right);
        }
        
        --freq[root->val];
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        buildPathAndCount(root);
        
        return count;
    }
};
