using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // 如果当前结点为空，则新建一个结点并返回
        if(!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        // 找到链表中的最小元素
        Node* curr = head;
        Node* next = head->next;

        while(curr->val <= next->val) {
            curr = curr->next;
            next = next->next;
            // 如果扫描整个链表一遍后又回到传入结点，则说明
            // 传入结点就是链表中最小元素所在位置
            if(curr == head) {
                break;
            }
        }
        Node* minElem = next;

        // 找到合适的插入位置
        while(next->val < insertVal) {
            curr = next;
            next = next->next;
            // 如果最后next回到了最小元素所在结点，则说明插入可以发生在
            // 任意位置
            if(next == minElem) {
                break;
            }
        }

        curr->next = new Node(insertVal);
        curr = curr->next;
        curr->next = next;

        return head;
    }
};
