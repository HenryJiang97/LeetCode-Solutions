// DFS with memo

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
class Solution {
    public Map<Node, Node> cloned = new HashMap<>();
    
    public Node cloneGraph(Node node) {
        // If cloned before, just load the memo
        if (cloned.containsKey(node))    return cloned.get(node);
        
        // If not cloned, create a new node
        Node newNode = new Node();
        newNode.val = node.val;
        
        List<Node> neiList = new ArrayList<>();
        newNode.neighbors = neiList;
        cloned.put(node, newNode);    // Save to memo
        
        for (Node nei : node.neighbors) {
            neiList.add(cloneGraph(nei));
        }
        
        return newNode;
    }
}