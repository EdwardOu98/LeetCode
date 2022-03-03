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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        for(int i = 0; i < k; ++i) {
            fast = fast->next;
        }

        ListNode* slow = head;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
