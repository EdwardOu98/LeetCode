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
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    
    ListNode* findMidNode(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        
        ListNode* curr = head;
        int len = 0;
        while(curr) {
            curr = curr->next;
            ++len;
        }
        if(len < 2) {
            return head;
        }
        
        ListNode* midNode = findMidNode(head);
        ListNode* midNext = midNode->next;
        midNode->next = nullptr;
        midNode = midNext;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(midNode);
        
        return mergeTwoLists(l1, l2);
    }
};
