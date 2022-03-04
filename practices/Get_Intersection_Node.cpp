#include <stdlib.h>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA) {
            ++a;
            tempA = tempA->next;
        }

        while(tempB) {
            ++b;
            tempB = tempB->next;
        }

        int diff = a - b;
        tempA = headA;
        tempB = headB;

        if(diff > 0) {
            for(int i = 0; i < diff; ++i) {
                tempA = tempA->next;
            }
        }
        else if(diff < 0){
            diff = abs(diff);
            for(int i = 0; i < diff; ++i) {
                tempB = tempB->next;
            }
        }

        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        if(!tempA && !tempB) {
            return NULL;
        }
        return tempA;
    }
};
