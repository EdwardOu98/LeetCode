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
    int calculateLength(ListNode* head) {
        ListNode* N = head;
        int count = 0;
        while(N) {
            ++count;
            N = N->next;
        }

        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA, *B = headB;

        // Calculate length of list A
        int countA = calculateLength(headA);

        // Calculate length of list B
        int countB = calculateLength(headB);


        if(countA >= countB) {
            for(int i = 0; i < countA - countB; ++i) {
                A = A->next;
            }
        }
        else {
            for(int i = 0; i < countB - countA; ++i) {
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
