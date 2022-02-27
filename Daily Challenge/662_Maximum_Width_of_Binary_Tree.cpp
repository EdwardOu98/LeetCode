#include <queue>
#include <algorithm>

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
// 思路：通过BFS找出最宽的一层
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        unsigned long maxWidth = 0;                 // Use unsigned long to avoid overflow
        queue<pair<TreeNode*, unsigned long>> q;    // TreeNode and its corresponding ID. 
                                                    // For left kids the ID is parentID * 2
                                                    // For right kids the ID is parentID * 2 + 1
        q.push({root, 1});
        
        while(!q.empty()) {
            unsigned long offset = q.front().second;
            int n = q.size();
            
            maxWidth = max(maxWidth, q.back().second - q.front().second + 1);
            for(int i = 0; i < n; ++i) {
                TreeNode* currNode = q.front().first;
                unsigned long currID = q.front().second;
                q.pop();

                if(currNode->left) {
                    q.push({currNode->left, 2 * (currID - offset)});
                }
                if(currNode->right) {
                    q.push({currNode->right, 2 * (currID - offset) + 1});
                }
            }
        }
        
        return maxWidth;
    }
};
