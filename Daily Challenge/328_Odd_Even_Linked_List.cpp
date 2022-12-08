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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* even = new ListNode(); // Used to temporarily hold the even nodes
        ListNode* oddCurr = head;
        ListNode* evenCurr = even;
        ListNode* next;
        ListNode* oddLast; // Save the last node of the odd list
        
        while(oddCurr && oddCurr->next) {
            next = oddCurr->next; // Get the even node
            oddCurr->next = next->next; // Connect the current odd node with the next
                                        // odd node
            evenCurr->next = next; // Connect the even node to the even list
            oddLast = oddCurr;
            oddCurr = oddCurr->next; // Move to the next odd node
            evenCurr = evenCurr->next; // Move to the next even node
            evenCurr->next = nullptr; // Disconnect the even node with the odd list
        }
        
        // If oddCurr isn't null, that means the original list contains odd number 
        // of nodes. Thus, we need to move the oddLast forward by 1 node to get to
        // the actual end of the odd list.
        if(oddCurr) {
           oddLast = oddCurr; 
        }
        
        oddLast->next = even->next;
        delete even;
        
        return head;
    }
};
