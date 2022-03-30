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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // If a cycle exist in the list, then before the slow
        // pointer and fast pointer meet at the same position,
        // fast pointer must have travelled through the cycle
        // for at least one pass. Let m be the length of list
        // before the cycle, n be the length of the cycle, and
        // k be the distance between the meeting point and the
        // beginning of the cycle. Then we have distance(fast) 
        // = m + n + k, and distance(slow) = m + k. Since the
        // fast pointer travelled twice as fast as the slow 
        // pointer, we have m + n + k = 2 * (m + k). Simplifying
        // the expression we have n = m + k or m = n - k. 
        // Now if we have one pointer start moving from the head
        // of the list and the other start moving from the meeting
        // point both moving one node forward at a time, 
        // when one of them is at the beginning of the cycle,
        // the other will also be at the same position.
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode* entry = head;
                while(entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }

        return NULL;
    }
};
