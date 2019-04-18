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

// Divide and Conquer

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return DAC(grid, 0, 0, grid.size());
    }
    

private:
    Node* DAC(vector<vector<int>>& grid, int x, int y, int len) {
        // Jump out of the recurrsion
        if (len == 1) {
            return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }
        
        // Divide
        int newLen = len / 2;    // New length for the next grid
        
        Node* topLeft = DAC(grid, x, y, newLen);
        Node* topRight = DAC(grid, x, y + newLen, newLen);
        Node* bottomLeft = DAC(grid, x + newLen, y, newLen);
        Node* bottomRight = DAC(grid, x + newLen, y + newLen, newLen);
        
        // Conquer
        Node* res = new Node();
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
            return new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};