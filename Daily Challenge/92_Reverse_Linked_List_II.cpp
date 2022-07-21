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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) {
            return head;
        }
        
        ListNode* newHead = new ListNode(0, head);
        ListNode* lprev = newHead;
        ListNode* lcurr = head;
        ListNode* rcurr = head;
        int i;
        for(i = 1; i < left; ++i) {
            lprev = lcurr;
            lcurr = lcurr->next;
        }
        
        for(i = 1; i < right; ++i) {
            rcurr = rcurr->next;
        }
        
        while(lprev->next != rcurr) {
            lcurr = lprev->next;
            lprev->next = lcurr->next;
            lcurr->next = rcurr->next;
            rcurr->next = lcurr;
        }
            
        return newHead->next;
    }
};
