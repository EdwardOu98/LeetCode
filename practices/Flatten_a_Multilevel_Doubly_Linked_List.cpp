using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) {
            return nullptr;
        }
        Node* temp = head;
        // 遍历整个链表
        while(temp) {
            // 如果当前结点有孩子结点，则将以孩子结点为头结点的链表
            // 插入到当前结点的后面
            if(temp->child) {
                Node* next = temp->next;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = nullptr;
                Node* p = temp->next;
                while(p->next) {
                    p = p->next;
                }
                p->next = next;
                if(next) {
                    next->prev = p;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};
