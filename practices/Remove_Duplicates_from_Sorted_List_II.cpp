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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // If the input node is empty, we return an empty node
        if(!head) {
            return nullptr;
        }
        
        // If the input node has an successive node and they have
        // the same value, we move forward on the list until the
        //  next node contains a different value
        if(head->next && head->next->val == head->val) {
            ListNode* temp;
            while(head->next) {
                if(head->next->val != head->val) {
                    break;
                    
                }
                temp = head->next;
                delete head;
                head = temp;
            }
            
            // Since we need to leave only the distinct nodes in
            // the original list in the result list, we return the
            // deletion result on the next node
            return deleteDuplicates(head->next);
        }
        
        // If the input node is distinct, we keep it in the list
        head->next = deleteDuplicates(head->next);
        
        return head;
    }
};
