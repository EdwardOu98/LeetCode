using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        
        if(!head->next) {
            return new TreeNode(head->val);
        }
        
        ListNode* mid = head;
        ListNode* fast = head->next;
        
        while(fast->next && fast->next->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        fast = mid->next;
        mid->next = nullptr;
        
        TreeNode* root = new TreeNode(fast->val);
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast->next);
        
        return root;
    }
};
