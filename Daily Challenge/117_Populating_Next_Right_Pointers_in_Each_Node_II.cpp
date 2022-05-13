using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    Node* connectNext(Node* root) {
        // If the input node is empty, return to the previous level
        if(!root) {
            return root;
        }
        
        // If root has a left child, then return its left child
        if(root->left) {
            return root->left;
        }
        
        // If root doesn't have a left child but has a right child,
        // return the right child
        if(root->right) {
            return root->right;
        }
        
        // If the root doesn't have any child, we need to consider
        // finding the left-most child from the root's next node
        return connectNext(root->next);
    }
public:
    Node* connect(Node* root) {
        // If the input node is empty, we don't need to do anything
        if(!root) {
            return root;
        }
        
        // If the current node has a left child, the left child's
        // next pointer should point to the root's right child
        // (if the root has a right child) or the root's next node's
        // left-most child
        if(root->left) {
            root->left->next = root->right ? root->right : connectNext(root->next);
        }
        
        // If the current node has a right child, the right child's
        // next pointer should point to the left-most child of the 
        // root's next node
        if(root->right) {
            root->right->next = connectNext(root->next);
        }
        
        // Because some of the nodes in the middle part of the tree
        // might be missing, we need complete information on the right
        // side of the tree before we make connection on the left side
        // so that we can guarentee the result is correct
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};
