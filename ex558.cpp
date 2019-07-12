/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* q1, Node* q2) {
        Node* res = new Node();
        res->isLeaf = false;
        res->val = NULL;
        
        if (q1->isLeaf && q2->isLeaf) {
            res->isLeaf = true;
            res->val = q1->val || q2->val;
            res->topLeft = NULL;
            res->topRight = NULL;
            res->bottomLeft = NULL;
            res->bottomRight = NULL;
            return res;	
        } 
		else if (q1->isLeaf)
		{
			// Return true immediately if one leaf node has true value 
            if (q1->val)    return new Node(true, true, NULL, NULL, NULL, NULL);
			
            res->topLeft = intersect(q1, q2->topLeft);
            res->topRight = intersect(q1, q2->topRight);
            res->bottomLeft = intersect(q1, q2->bottomLeft);
            res->bottomRight = intersect(q1, q2->bottomRight);	
        } 
		else if (q2->isLeaf) 
		{
			// Return true immediately if one leaf node has true value 
            if (q2->val)    return new Node(true, true, NULL, NULL, NULL, NULL);
			
            res->topLeft = intersect(q1->topLeft, q2);
            res->topRight = intersect(q1->topRight, q2);
            res->bottomLeft = intersect(q1->bottomLeft, q2);
            res->bottomRight = intersect(q1->bottomRight, q2);
        } 
		else 
		{
            res->topLeft = intersect(q1->topLeft, q2->topLeft);
            res->topRight = intersect(q1->topRight, q2->topRight);
            res->bottomLeft = intersect(q1->bottomLeft, q2->bottomLeft);
            res->bottomRight = intersect(q1->bottomRight, q2->bottomRight);
        }
        
        // If all four children have the same val and are leaves, combine them into one grid
        if (res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf && res->topLeft->val == res->topRight->val && res->topRight->val == res->bottomLeft->val && res->bottomLeft->val == res->bottomRight->val && res->bottomRight->val == res->topLeft->val)
            return new Node(res->topLeft, true, NULL, NULL, NULL, NULL);
        
        return res;
    }
};