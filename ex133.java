// DFS

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    private HashMap<Node, Node> visited = new HashMap<>();
    
    public Node cloneGraph(Node node) {
        // If map already contains the node, just return it
        if (visited.containsKey(node))    return visited.get(node);
        
        // Create new cloned node
        Node clone = new Node();
        clone.val = node.val;
        visited.put(node, clone);    // Add node to visited for later use
        
        // Clone neighbors list
        List<Node> nei = new ArrayList<>();
        for (Node n : node.neighbors) {
            Node nclone = cloneGraph(n);
            nei.add(nclone);
        }
        
        clone.neighbors = nei;
        
        return clone;
    }
}