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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n == 1) {
            return nullptr;
        }
        ListNode* fast = head;
        for(int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        ListNode* slow = head;
        ListNode* tempHead = new ListNode(0, head);
        ListNode* prev = tempHead;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
            prev = prev->next;
        }

        prev->next = slow->next;
        

        return tempHead->next;
    }
};
