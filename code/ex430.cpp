/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* p = head;
        while (p != NULL) {
            if (p->child != NULL) {
                Node* nxt = p->next;
                Node* nxtLevel = flatten(p->child);
                p->next = flatten(p->child);
                p->child = NULL;
                p->next->prev = p;
                while (p->next != NULL)    p = p->next;
                p->next = nxt;
                if (nxt != NULL)    nxt->prev = p;
            }
            p = p->next;
        }
        return head;
    }
};