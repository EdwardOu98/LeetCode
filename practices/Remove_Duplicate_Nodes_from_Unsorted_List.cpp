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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* curr = head->next, *prev = head;
        int numSet[20001] = {0};
        numSet[head->val] = 1;

        while(curr) {
            if(!numSet[curr->val]) {
                ++numSet[curr->val];
                prev = curr;
                curr = curr->next;
            }
            else{
                prev->next = curr->next;
                curr = prev->next;
            }
        }

        return head;
    }
};
