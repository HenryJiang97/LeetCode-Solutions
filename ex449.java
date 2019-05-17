/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.*;

public class Codec {
    
    // Get the postorder traverse sequence of the tree
    private String helper(TreeNode root) {
        // Postorder traverse
        if (root == null)    return "";
        
        String data = "";
        String left = helper(root.left), right = helper(root.right);
        if (left != "")    data = data + "," + left;
        if (right != "")    data = data + "," + right;
        data = data + "," + String.valueOf(root.val);
        
        return data;
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String res = helper(root);
        StringBuilder sb = new StringBuilder(res);
        
        int i = 1;
        while (i < sb.length()) {
            if (sb.charAt(i) == ',' && sb.charAt(i - 1) == ',') {
                sb.deleteCharAt(i);
            } else {
                i++;
            }    
        }
        if (sb.length() != 0 && sb.charAt(0) == ',')    sb.deleteCharAt(0);
        String data = sb.toString();
        System.out.println(data);
        return data;
    }

    // Get the original tree from the array
    private TreeNode helper2(int[] array) {
        if (array.length == 0)    return null;
        
        int root = array[array.length - 1];
        int index = -1;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > root) {
                index = i;
                break;
            }
        }
        if (index == -1)    index = array.length - 1;
        
        TreeNode rootNode = new TreeNode(root);
        TreeNode leftNode = helper2(Arrays.copyOfRange(array, 0, index));
        TreeNode rightNode = helper2(Arrays.copyOfRange(array, index, array.length - 1));
        rootNode.left = leftNode;
        rootNode.right = rightNode;
        
        return rootNode;
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.length() == 0)    return null;
        
        String[] sarray = data.split(",");
        int[] array = new int[sarray.length];
        for (int i = 0; i < array.length; i++) {
            array[i] = Integer.parseInt(sarray[i]);
        }
        
        return helper2(array);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));