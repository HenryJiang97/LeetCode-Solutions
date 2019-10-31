/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    private String res;
    public String serialize(TreeNode root) {
        res = "";
        dfs(root);
        return res;
    }
    
    // DFS
    private void dfs(TreeNode root) {
        if (root == null) {
            res += "NULL" + ",";
            return;
        }
        res = res + String.valueOf(root.val) + ",";
        dfs(root.left);
        dfs(root.right);
    }

    // Decodes your encoded data to tree.
    private int p = 0;
    public TreeNode deserialize(String data) {
        return buildTree(data);
    }
    
    private TreeNode buildTree(String data) {
        String val = nextVal(data);
        if (val.equals("NULL"))    return null;
        TreeNode root = new TreeNode(Integer.parseInt(val));
        root.left = buildTree(data);
        root.right = buildTree(data);
        return root;
    }
    
    private String nextVal(String data) {
        String s = "";
        while (data.charAt(p) != ',') {
            s += data.charAt(p++);
        }
        p++;
        return s;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));