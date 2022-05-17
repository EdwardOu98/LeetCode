using namespace std;

class StreamRank {
private:
    typedef struct TreeNode {
        int val; // Value of the current node
        int rankk;// Number of nodes in the current node's left subtree (including self)
        struct TreeNode* left;
        struct TreeNode* right; 
        TreeNode() {}
        TreeNode(int x) : val(x), rankk(1), left(nullptr), right(nullptr) {}
    } TreeNode;

    // Insert a new value to the BST
    void insert(TreeNode* root, int x) {
        // If the new value is greater than the current node's value
        if(root->val < x) {
            // If the current node has a right child, insert the new value
            // in the right subtree
            if(root->right) {
                insert(root->right, x);
            }
            // If the current node doesn't have a right child, create a new
            // node as the right child of the current node
            else {
                root->right = new TreeNode(x);
            }
        }
        // If the new value is less than the current node's value
        else if(root->val > x) {
            // Increment the rankk of the current node
            ++root->rankk;
            // If the current node has a left child, insert the new value
            // in the left subtree
            if(root->left) {
                insert(root->left, x);
            }
            // If the current node doesn't have a left child, create a new
            // node as the left child of the current node
            else {
                root->left = new TreeNode(x);
            }
        }
        // If the new value is equal to the current node's value, increment
        // the rank of the current node
        else {
            ++root->rankk;
        }
    }

    int search(TreeNode* root, int x) {
        if(!root) {
            return 0;
        }
        // If the current node's value is equal to x, return its rank
        if(root->val == x) {
            return root->rankk;
        }
        // If the current node's value is smaller than x, search for x
        // in the left subtree
        else if(root->val > x) {
            return search(root->left, x);
        }
        // If the current node's value is greater than x, search for x
        // in the right subtree, and sum the result with the current 
        // node's rank
        return root->rankk + search(root->right, x);
    }

    TreeNode* root = nullptr;
public:
    StreamRank() {

    }
    
    void track(int x) {
        if(!root) {
            root = new TreeNode(x);
        }
        else {
            insert(root, x);
        }
    }
    
    int getRankOfNumber(int x) {
        return search(root, x);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
