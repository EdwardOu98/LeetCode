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
public:
    Node* connect(Node* root) {
        // If root is NULL, return NULL
        if(!root) {
            return nullptr;
        }
        
        // If root has a left child, the left child's next pointer
        // should points to its right child. 
        if(root->left) {
            root->left->next = root->right;
            // If root's next pointer has been populated, the right
            // child's next pointer should point to the next node's
            // left child
            if(root->next) {
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        
        return root;
    }
};
