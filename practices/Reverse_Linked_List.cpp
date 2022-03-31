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
};