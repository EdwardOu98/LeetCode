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
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return head;
        }
        
        ListNode* left = new ListNode();    // Stores elements smaller than x
        ListNode* right = new ListNode();   // Stores elements greater than or
                                            // equal to x
        
        ListNode* lcurr = left;
        ListNode* rcurr = right;
        ListNode* curr = head;
        ListNode* temp;
        
        while(curr) {
            temp = curr->next;
            curr->next = nullptr;
            
            // If the value stored in the current
            // node is smaller than x, we put it
            // into the left list. Otherwise, we 
            // put it into the right list.
            if(curr->val < x) {
                lcurr->next = curr;
                lcurr = lcurr->next;
            }
            else {
                rcurr->next = curr;
                rcurr = rcurr->next;
            }
            
            curr = temp;
        }
        
        // If the left list is empty, that means
        // all the elements in the original list
        // are greater than or equal to x. Thus, 
        // we return the contents of the right
        // list
        if(!left->next) {
            head = right->next;
        }
        // If the left list is not empty, we let
        // head be the first data node of the left
        // list. And because lcurr is pointing to
        // the last node of the left list, we let
        // the next pointer of lcurr points to the
        // first data node of the right list. Now
        // we have a complete list with nodes arranged
        // in a way that the nodes whose values are
        // smaller than x are in the front part of the
        // list and others are in the back. 
        else {
            head = left->next;
            lcurr->next = right->next;
        }
        
        
        // Deallocate the extra space used to
        // rearrange the nodes
        delete left;
        delete right;
        
        return head;
    }
};
