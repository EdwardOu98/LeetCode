using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Move the node values behind the given node
        // one slot ahead until the second to last node
        while(node->next->next) {
            node->val = node->next->val;
            node = node->next;
        }
        
        // At the second to last node, we need to copy the
        // value and set the next pointer to null
        node->val = node->next->val;
        node->next = nullptr;
    }
};
