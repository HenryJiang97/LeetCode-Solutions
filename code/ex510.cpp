/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right != NULL)    return getLeftMost(node->right);
        Node* p = node;
        while (p->parent != NULL) {
            Node* parent = p->parent;
            if (parent->left == p)
                return parent;
            p = parent;
        }
        if (node->right != NULL)    return getLeftMost(node->right);
        return NULL;
    }
    
private:
    Node* getLeftMost(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }
};