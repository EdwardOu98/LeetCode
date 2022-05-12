#include <vector>

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
class Solution { 
private:
    void generate(int p1, int p2, vector<int>& s1, vector<int>& s2, vector<int>& temp, vector<vector<int>>& res) {
        // If all elements in both s1 and s2 are used up, add temp to the result array
        if(p1 == s1.size() && p2 == s2.size()) {
            res.push_back(temp);
            return;
        }

        // If there are still unused element in s1, take one
        // element from s1 and add it to temp, then continue
        // to the next level 
        if(p1 < s1.size()) {
            temp.push_back(s1[p1]);
            generate(p1 + 1, p2, s1, s2, temp, res);
            temp.pop_back();
        }

        // If there are still unused element in s2, take one
        // element from s2 and add it to temp, then continue
        // to the next level 
        if(p2 < s2.size()) {
            temp.push_back(s2[p2]);
            generate(p1, p2 + 1, s1, s2, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        // If the tree is empty, return an array that contains an
        // empty array
        if(!root) {
            return {{}};
        }

        // Find the BST sequence of the left and right subtree
        vector<vector<int>> left = BSTSequences(root->left);
        vector<vector<int>> right = BSTSequences(root->right);

        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(root->val);
        // Combine the left and right subsequence
        for(int i = 0; i < left.size(); ++i) {
            for(int j = 0; j < right.size(); ++j) {
                generate(0, 0, left[i], right[j], temp, res);
            }
        }

        return res;
    }
};
