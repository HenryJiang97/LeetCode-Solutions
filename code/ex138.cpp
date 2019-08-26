/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> map;
    
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)    return NULL;
        
        // Define new node
        Node* newNode = new Node();
        map.insert({head, newNode});
        
        // Build new node
        newNode->val = head->val;
        newNode->next = map.find(head->next) != map.end() ? map[head->next] : copyRandomList(head->next);
        newNode->random = map.find(head->random) != map.end() ? map[head->random] : copyRandomList(head->random);
        
        return newNode;
    }
};