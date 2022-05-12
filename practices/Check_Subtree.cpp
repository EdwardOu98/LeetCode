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
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        // If both trees are empty trees, return true
        if(!t1 && !t2) {
            return true;
        }

        // If only one of them is an empty tree, return false
        if(!t1 || !t2) {
            return false;
        }

        // If the values of the two roots are not the same,
        // return false
        if(t1->val != t2->val) {
            return false;
        }

        // Check whether the left and right subtree are the same
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        // If both trees are empty trees, return true
        if(!t1 && !t2) {
            return true;
        }

        // If only one of them is an empty tree, return false
        if(!t1 || !t2) {
            return false;
        }

        // Check whether t1 and t2 are the same tree, or whether t2 is the same as t1's left
        // or right tree
        return isSameTree(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};
