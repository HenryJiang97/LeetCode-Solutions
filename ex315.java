import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

// BST

// Define the node structure
class BSTnode {
    // val: node value
    // appearence: How many times the value appears in the list
    // left_num: number of value which is smaller than the node
    int val;
    int appearence = 1;
    int left_num = 0;
    
    //Init
    public BSTnode(int v) {val = v;}
    
    // Left and Right nodes
    BSTnode left = null, right = null;
}


class Solution {
    // Function to insert a new node to the tree
    public static int insert(BSTnode p, int v) {
        int count = 0;
        BSTnode q = null;    //q is to record the last position of p
        
        while (p != null) {
            q = p;
            
            if (v == p.val) {
                p.appearence++;
                count += p.left_num;
                return count;
            }
            else if (v < p.val) {
                p.left_num++;
                p = p.left;
            }
            else if (v > p.val) {
                count = count + p.appearence + p.left_num; 
                p = p.right;
            }
        }
        
        // Link the new node
        if (v < q.val)    q.left = new BSTnode(v);
        else if (v > q.val)    q.right = new BSTnode(v);
        
        return count;
    }
    
    
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();
        
        // Secial situations
        if (nums.length == 0)   return result;
        else if (nums.length == 1)    return new ArrayList<>(Arrays.asList(0));
        
        // Build a BST, search and count (Each node has two elements(Appearence time, number of left children))
        BSTnode root = new BSTnode(nums[nums.length - 1]);
        result.add(0);
        
        for (int i = nums.length - 2; i >= 0; i--)
            result.add(0, insert(root, nums[i]));
            
        
        return result;
    }
}