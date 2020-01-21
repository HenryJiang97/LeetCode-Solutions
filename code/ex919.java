/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class CBTInserter {
    private TreeNode head;
    private Queue<TreeNode> queue;

    public CBTInserter(TreeNode root) {
        this.head = root;
        queue = new LinkedList<>();
        queue.offer(root);
        while (true) {
            TreeNode out = queue.peek();
            if (out.left != null)    queue.offer(out.left);
            if (out.right != null)    queue.offer(out.right);
            if (out.left != null && out.right != null)    queue.poll();
            else    break;
        }
    }
    
    public int insert(int v) {
        TreeNode out = queue.peek();
        TreeNode newNode = new TreeNode(v);
        if (out.left == null)    out.left = newNode;
        else {
            out.right = newNode;
            queue.poll();
        }
        queue.offer(newNode);
        return out.val;
    }
    
    public TreeNode get_root() {
        return head;
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */