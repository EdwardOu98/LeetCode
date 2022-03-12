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
        unordered_map<Node*, Node*> copies;
        Node* temp = head;
        
        while(temp) {
            copies[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp) {
            if(temp->next) {
                copies[temp]->next = copies[temp->next];
            }
            if(temp->random) {
                copies[temp]->random = copies[temp->random];
            }
            temp = temp->next;
        }
        
        return copies[head];
    }
};
