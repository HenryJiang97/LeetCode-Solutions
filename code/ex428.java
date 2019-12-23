/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 1[3[5 6] 2 4]

class Codec {

    // Encodes a tree to a single string.
    public String serialize(Node root) {
        String res = helper(root);
        return res;
    }
    
    private String helper(Node root) {
        if (root == null)    return "";
        String res = String.valueOf(root.val);
        if (root.children.size() == 0)    return res;
        
        res += "[";
        for (Node child : root.children) {
            String next = helper(child);
            if (next.equals(""))    continue;
            res += next + " ";
        }
        
        res = res.trim();
        res += "]";
        return res; 
    }

    // Decodes your encoded data to tree.
    private int p = 0;
    
    public Node deserialize(String data) {
        if (data.equals(""))    return null;
        
        String v = "";
        while (p < data.length()) {
            if (Character.isDigit(data.charAt(p))) {
                v += data.charAt(p++);
            } else {
                break;
            }
        }
        Node root = new Node(Integer.parseInt(v));
        p++;
        root.children = helper2(data);
        return root;
    }
    
    private List<Node> helper2(String data) {
        List<Node> nodes = new ArrayList<>();
        if (p >= data.length())    return nodes;
        
        String v = "";
        while (p < data.length()) {
            if (data.charAt(p) == '[') {
                p++;
                Node node = new Node(Integer.parseInt(v));
                node.children = helper2(data);
                nodes.add(node);
                v = "";
            } else if (data.charAt(p) == ']') {
                if (Character.isDigit(data.charAt(p - 1))) {
                    Node node = new Node(Integer.parseInt(v));
                    node.children = new ArrayList<Node>();
                    nodes.add(node);
                }
                p++;
                return nodes;
            } else if (data.charAt(p) == ' ') {
                if (data.charAt(p - 1) != ']') {
                    Node node = new Node(Integer.parseInt(v));
                    node.children = new ArrayList<Node>();
                    nodes.add(node);
                    v = "";
                }
                p++;
            } else {
                v += data.charAt(p++);
            }
        }
        
        return nodes;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));