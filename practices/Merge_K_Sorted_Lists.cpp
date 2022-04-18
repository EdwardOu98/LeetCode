#include <vector>
#include <queue>
#include <type_traits> // decltype

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
    void mergeTwoLists(ListNode* &l1, ListNode* &l2) {
        if(!l1) {
            l1 = l2;
            return;
        }

        if(!l2) {
            return;
        }

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

    }

    ListNode* mergeSort(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }

        int n = lists.size(), i;

        if(n == 1){
            return lists[0];
        }

        while(n > 1) {
            for(i = 0; i < n / 2; ++i) {
                mergeTwoLists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }

        return lists.front();
    }

    ListNode* priorityQueue(vector<ListNode*>& lists) {
        auto cmp = [] (const ListNode* p1, const ListNode* p2) {
            return p1->val > p2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(ListNode* l : lists) {
            while(l) {
                pq.push(l);
                l = l->next;
            }
        }

        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;

        while(!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
        }

        if(curr) {
            curr->next = NULL;
        }

        return newHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists);
        // return priorityQueue(lists);
    }
};
