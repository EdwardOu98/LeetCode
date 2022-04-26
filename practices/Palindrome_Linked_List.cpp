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
    ListNode* reverseList(ListNode* head) {
        ListNode* tempHead = new ListNode();
        ListNode* next;
        while(head) {
            next = head->next;
            head->next = tempHead->next;
            tempHead->next = head;
            head = next;
        }
        
        return tempHead->next;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        // Find the middle node
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast) {
            slow = slow->next;
        }
        
        // Reverse the later half of the list
        slow = reverseList(slow);
        
        while(slow) {
            if(head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};
