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
    ListNode* deleteNode(ListNode* head, int key) {
        if(!head) {
            return head;
        }

        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* tmp = newHead;

        while(tmp && tmp->next) {
            if(tmp->next->val == key) {
                tmp->next = tmp->next->next;
                break;
            }
            tmp = tmp->next;
        }

        return newHead->next;
    }
};
