#include <stack>

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
        // 新建一个头结点
        ListNode* tempHead = new ListNode();

        // 用于暂存每个结点的next指针的内容
        ListNode* next;

        // 只要当前待插入结点不为空就一直执行下去
        while(head) {
            // 先将当前待插入结点的next指针保存下来
            next = head->next;
            // 将待插入结点的next指针指向新建头结点的下一个结点
            head->next = tempHead->next;
            // 将新建头结点的next指针指向当前待插入结点完成插入操作
            tempHead->next = head;
            // head指针移向下一个待插入结点
            head = next;
        }

        // 新建头结点的下一个结点就是链表反转后的第一个数据结点
        return tempHead->next;
    }

    void reorder(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;

        // 找到中点
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 如果结点个数是奇数则需要再将慢指针前移一位
        if(fast) {
            prev = slow;
            slow = slow->next;
        }

        // 将链表从中间切成两段
        prev->next = nullptr;

        // 翻转链表的后半段
        slow = reverseList(slow);
        fast = head;
        ListNode* next;

        while(slow) {
            next = fast->next;
            fast->next = slow;
            slow = slow->next;
            fast->next->next = next;
            fast = next;
        }
    }
    void reorderWithStack(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;

        // 找到中点
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 如果结点个数是奇数则需要再将慢指针后移一位
        if(fast) {
            prev = slow;
            slow = slow->next;
        }

        // 将链表从中间切成两段
        prev->next = nullptr;

        // 将链表后半段入栈
        while(slow) {
            stk.push(slow);
            slow = slow->next;
        }

        slow = head;
        // 将栈内结点插入到合适的位置上
        while(!stk.empty()) {
            stk.top()->next = slow->next;
            slow->next = stk.top();
            stk.pop();
            slow = slow->next->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        reorder(head);
        // reorderWithStack(head);
    }
};
