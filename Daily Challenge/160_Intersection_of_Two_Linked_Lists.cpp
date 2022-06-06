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
private:
    int listLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp) {
            temp = temp->next;
            ++len;
        }
        
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = listLength(headA), len2 = listLength(headB);
        ListNode* A = headA;
        ListNode* B = headB;
        if(len1 > len2) {
            for(int i = 0; i < len1 - len2; ++i) {
                A = A->next;
            }
        }
        else {
            for(int i = 0; i < len2 - len1; ++i) {
                B = B->next;
            }
        }
        
        while(A != B) {
            A = A->next;
            B = B->next;
        }
        
        return A;
    }
};
