#include <vector>

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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }
        
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        
        for(int i = start; i <= end; ++i) {
            left = generateTrees(start, i - 1);
            right = generateTrees(i + 1, end);
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i, l, r);
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
