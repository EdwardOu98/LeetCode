#include <stack>
#include <vector>

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
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> res;
        ListNode* tmp;
        tmp = head;

        while(tmp) {
            stk.push(tmp->val);
            tmp = tmp->next;
        }

        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};
