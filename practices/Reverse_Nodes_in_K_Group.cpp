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
    ListNode* reverse(ListNode* first, ListNode* last) {
        ListNode* prev = last;
        while(first != last) {
            ListNode* temp = first->next;
            first->next = prev;
            prev = first;
            first = temp;
        }
        
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* n = head;
        for(int i = 0; i < k; ++i) {
            if(n) {
                n = n->next;
            }
            else {
                return head;
            }
        }
        
        ListNode* res = reverse(head, n);
        head->next = reverseKGroup(n, k);
        
        return res;
    }
};
