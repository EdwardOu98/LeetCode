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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) {
            return head;
        }
        
        ListNode* newHead = new ListNode(0, head);
        int len = 0;
        ListNode* curr = newHead;
        
        while(curr->next) {
            curr = curr->next;
            ++len;
        }
        
        int MOD = k % len;
        if(MOD == 0) {
            return head;
        }
        
        curr->next = head;
        curr = newHead;
        
        for(int i = len - MOD; i > 0; --i) {
            curr = curr->next;
        }
        
        newHead->next = curr->next;
        curr->next = nullptr;
        
        return newHead->next;
    }
};
