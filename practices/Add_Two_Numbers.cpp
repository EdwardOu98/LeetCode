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

    // 先反转两个输入链表再相加
    ListNode* reverseThenAdd(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        // 进位信息
        int carry = 0;
        // 当前位的和
        int sum;
        ListNode* tempHead = new ListNode();

        // 当两个链表的当前结点都不为空时
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10; // 进位为加和结果的十位
            sum %= 10;  // 当前位应保存加和的个位
            tempHead->next = new ListNode(sum, tempHead->next);;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;
            tempHead->next = new ListNode(sum, tempHead->next);
            l1 = l1->next;
        }

        while(l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            tempHead->next = new ListNode(sum, tempHead->next);
            l2 = l2->next;
        }

        if(carry) {
            tempHead->val = carry;
            return tempHead;
        }

        return tempHead->next;
    }

    // 递归实现:
    // 需要先计算两个链表的长度，然后将长度更长的链表的头结点对应的下标设为0，较短的链表的头结点
    // 下标为两链表长度的差值。当两个下标相等时说明从这个结点处开始两个链表的长度相等，无需特殊处理
    // 可以直接计算。
    ListNode* recurrsion(ListNode* l1, ListNode* l2, int idx1, int idx2, int& carry) {
        if(!l1 || !l2) {
            return nullptr;
        }
        ListNode* temp = new ListNode();
        int sum;
        // 如果两个下标不相等，则需要将两个链表“对齐”
        // 如果l1结点的下标比l2结点的下标小，说明l1更长，此时需要将l1的下一个结点传入递归
        // 函数并将idx1加1
        if(idx1 < idx2) {            
            temp->next = recurrsion(l1->next, l2, idx1+1, idx2, carry);
            sum = l1->val + carry;
            carry = sum / 10;
            temp->val = sum % 10;
            return temp;
        }
        // 如果l2结点的下标比l1结点的下标小，说明l2更长，此时需要将l2的下一个结点传入递归
        // 函数并将idx2加1
        else if(idx2 < idx1) {
            temp->next = recurrsion(l1, l2->next, idx1, idx2+1, carry);
            sum = l2->val + carry;
            carry = sum / 10;
            temp->val = sum % 10;
            return temp;
        }

        temp->next = recurrsion(l1->next, l2->next, idx1+1, idx2+1, carry);
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        temp->val = sum % 10;
        return temp;
    }

    // 计算链表长度
    int calculateLength(ListNode* head) {
        ListNode* N = head;
        int count = 0;
        while(N) {
            ++count;
            N = N->next;
        }

        return count;
    }

    // 用栈实现
    // 时间复杂度和空间复杂度都是O(n)
    ListNode* addWithStack(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* tempHead = new ListNode();
        int sum, carry = 0;
        while(!s1.empty() && !s2.empty()) {
            sum = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            carry = sum / 10;
            sum %= 10;
            tempHead->next = new ListNode(sum, tempHead->next);
        }

        while(!s1.empty()) {
            sum = s1.top() + carry;
            s1.pop();
            carry = sum / 10;
            sum %= 10;
            tempHead->next = new ListNode(sum, tempHead->next);
        }

        while(!s2.empty()) {
            sum = s2.top() + carry;
            s2.pop();
            carry = sum / 10;
            sum %= 10;
            tempHead->next = new ListNode(sum, tempHead->next);
        }

        if(carry) {
            tempHead->val = carry;
            return tempHead;
        }
        return tempHead->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return reverseThenAdd(l1, l2);
        // return addWithStack(l1, l2);
        ListNode* temp = new ListNode();
        int count1 = calculateLength(l1), count2 = calculateLength(l2);
        int idx1, idx2;
        if(count1 > count2) {
            idx1 = 0;
            idx2 = count1 - count2;
        }
        else {
            idx1 = count2 - count1;
            idx2 = 0;
        }

        int carry = 0;
        temp->next = recurrsion(l1, l2, idx1, idx2, carry);
        if(carry) {
            temp->val = carry;
            return temp;
        }
        return temp->next;
    }
};
