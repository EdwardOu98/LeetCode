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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
// Basic Idea: Use level-order traversal of the binary tree,
// create a linked list for each level
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        // If the tree is empty, return an empty array
        if(!tree) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(tree);

        ListNode* temp = new ListNode(0);
        ListNode* curr;

        vector<ListNode*> res;

        while(!q.empty()) {
            int n = q.size();
            curr = temp;
            while(n--) {
                // Get the front node in the queue
                TreeNode* node = q.front();
                q.pop();
                // Add the node to the Current level's list
                curr->next = new ListNode(node->val);
                curr = curr->next;

                // If the current node have left/right child, add the
                // child to the queue
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            // Add the current level's list to the result array
            res.push_back(temp->next);
        }

        return res;
    }
};
