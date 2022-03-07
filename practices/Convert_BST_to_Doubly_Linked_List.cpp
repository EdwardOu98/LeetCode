using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    void InOrder(Node* root, Node* &head, Node* &tail) {
        if(root) {
            InOrder(root->left, head, tail);
            if(head == nullptr) {
                head = tail = root;
            }
            else {
                tail->right = root;
                root->left = tail;
                tail = root;
            }
            InOrder(root->right, head, tail);
        }
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) {
            return nullptr;
        }
        Node* head = nullptr, *tail = nullptr;
        InOrder(root, head, tail);
        head->left = tail;
        tail->right = head;

        return head;
    }
};
