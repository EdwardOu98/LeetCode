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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* newHead = new ListNode();
        newHead->next = head;

        while(p && p->next) {
            p = p->next;
        }

        ListNode* tmp;
        while(newHead->next != p) {
            tmp = newHead->next;
            newHead->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
        }

        return newHead->next;
    }
};
