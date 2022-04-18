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
        if(!root) {
            return nullptr;
        }
        
        if(root->left) {
            return root->left;
        }
        
        if(root->right) {
            return root->right;
        }
        
        return connectNext(root->next);
    }
public:
    Node* connect(Node* root) {
        if(!root) {
            return nullptr;
        }
        
        // If root has a left child, then its next pointer should 
        // be connect to either the right child or the root's next
        // node's left-most child
        if(root->left) {
            root->left->next = root->right ? root->right : connectNext(root->next);
        }
        
        
        // If root has a right child, then its next pointer should
        // be connected to the root's next node's left-most child
        if(root->right) {
            root->right->next = connectNext(root->next);
        }
        
        // We need to connect the right half of the tree first. Because
        // when the nodes in the middle of the tree is missing, we need
        // complete information on the right side of the tree to get the 
        // correct result
        connect(root->right);
        connect(root->left);       
        
        return root;
    }
};
