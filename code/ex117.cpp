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
        if (root == NULL)    return NULL;
        
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                Node* out = que.front();    que.pop();
                if (size >= 1)    out->next = que.front();
                if (out->left != NULL)    que.push(out->left);
                if (out->right != NULL)    que.push(out->right);
            }
        }
        
        return root;
    }
};