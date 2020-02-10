class Solution {
    public boolean verifyPreorder(int[] preorder) {
        if (preorder.length <= 2)    return true;
        Stack<Integer> stack = new Stack<>();
        int root = Integer.MIN_VALUE;
        for (int node : preorder) {
            // Go over the left part of a subtree
            while (!stack.isEmpty() && node > stack.peek()) {
                root = stack.pop();
            }
            if (node < root)    return false;    // Test the right part of a subtree
            stack.push(node);
        }
        return true;
    }
}