#include <vector>
#include <algorithm>

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
    ListNode* constantSpace(ListNode* head, int k) {
        ListNode* node1 = head;
        for(int i = 1; i < k; ++i) {
            node1 = node1->next;
        }
        ListNode* node2 = head;
        ListNode* temp = node1;
        while(temp->next) {
            temp = temp->next;
            node2 = node2->next;
        }
        
        int val = node1->val;
        node1->val = node2->val;
        node2->val = val;
        
        return head;
    }
    
    ListNode* linearSpace(ListNode* head, int k) {
        vector<int> auxiliaryArray;
        ListNode* temp = head;
        int n = 0;
        while(temp) {
            ++n;
            auxiliaryArray.push_back(temp->val);
            temp = temp->next;
        }
        
        swap(auxiliaryArray[k - 1], auxiliaryArray[n - k]);
        
        temp = head;
        for(int i = 0; i < n; ++i) {
            temp->val = auxiliaryArray[i];
            
            temp = temp->next;
        }
        return head;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        return constantSpace(head, k);
        // return linearSpace(head, k);
    }
};
