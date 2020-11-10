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
    
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)    return NULL;
        stack<Node*> stk;
        addLeft(stk, root);
        Node* head = NULL;
        Node* prev = NULL;
        while (!stk.empty()) {
            Node* cur = stk.top();    stk.pop();
            if (head == NULL)    head = cur;
            if (prev != NULL) {
                prev->right = cur;
                cur->left = prev;
            }
            addLeft(stk, cur->right);
            prev = cur;
        }
        prev->right = head;
        head->left = prev;
        return head;
    }
    
private:
    void addLeft(stack<Node*>& stk, Node* p) {
        while (p != NULL) {
            stk.push(p);
            p = p->left;
        }
    }
};