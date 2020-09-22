/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* p = head;
        int len = 0, i = 0;
        while (1) {
            len++;
            if (p->next == head)    break;
            p = p->next;
        }
        p = head;
        while (1) {
            if (p->val > p->next->val || i == len - 1) {    // End of the linked list
                if (insertVal >= p->val || insertVal <= p->next->val) {
                    insertNode(p, insertVal);
                    break;
                }
            } else {
                if (insertVal >= p->val && insertVal <= p->next->val) {
                    insertNode(p, insertVal);
                    break;
                }
            }
            p = p->next;
            i++;
        }
        return head;
    }
    
private:
    void insertNode(Node*& p, int val) {
        Node* newN = new Node(val);
        newN->next = p->next;
        p->next = newN;
    }
};