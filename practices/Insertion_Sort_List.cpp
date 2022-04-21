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
    ListNode* insertionSortList(ListNode* head) {
        // If input list is empty, return
        if(!head) {
            return head;
        }
        
        ListNode* newHead = new ListNode();
        ListNode* prev;
        ListNode* next;
        ListNode* curr = head;
        
        // Iterate through the input list, insert them into the list
        // in accending order
        while(curr) {
            prev = newHead;
            next = curr->next;
            while(prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        
        return newHead->next;
    }
};
