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
        if (node->right != NULL) {
            node = node->right;
            while (node->left != NULL)    node = node->left;
            return node;
        } else {
            while (node->parent != NULL && node->parent->right == node)
                node = node->parent;
            node = node->parent;
            if (node == NULL)    return NULL;
            else    return node;
        }
    }
};