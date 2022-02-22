#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        unordered_map<Node*, Node*> copies;
        Node* n = head;
        while(n) {
            copies[n] = new Node(n->val);
            n = n->next;
        }

        n = head;

        while(n) {
            copies[n]->next = copies[n->next];
            copies[n]->random = copies[n->random];
            n = n->next;
        }

        return copies[head];
    }
};
