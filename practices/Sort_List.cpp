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
    ListNode* merge (ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        while(l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }

        while(l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }

        curr->next = NULL;

        l1 = newHead->next;
        delete newHead;
        return l1;
    } 

    ListNode* mergeSort (ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = head;

        while(prev->next != slow) {
            prev = prev->next;
        }

        prev->next = NULL;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(slow);

        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
