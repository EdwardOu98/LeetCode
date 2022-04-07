#include <vector>
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
public:
    vector<int> largestValues(TreeNode* root) {
        // 如果根结点为空，直接返回一个空数组
        if(!root) {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int n, i, maxVal;
        TreeNode* temp;

        // 层序遍历
        while(!q.empty()) {
            n = q.size();
            maxVal = INT_MIN;
            for(i = 0; i < n; ++i) {
                temp = q.front();
                q.pop();
                maxVal = max(maxVal, temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            res.push_back(maxVal);
        }

        return res;
    }
};
