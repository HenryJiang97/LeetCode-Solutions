// Trie

class Solution {
    // Definition of trie tree (Binary form)
    public class Trie {
        int val;
        Trie left;    // For '1'
        Trie right;    // For '0'
        public Trie (int val) {
            this.val = val;
        }
    }
    
    // Insert every number to the trie tree
    public void insert(Trie trie, int num) {
        // Get each bit of num from left to right
        for (int i = 31; i >= 0; i--) {
            int bit = (num & (1 << i)) / (int)Math.pow(2, i);
            
            if (bit == 0) {
                if (trie.right == null)    trie.right = new Trie(0);
                trie = trie.right;
            } else {
                if (trie.left == null)    trie.left = new Trie(1);
                trie = trie.left;
            }
        }
        
        trie.val = num;
    }
    
    // Get the pair of num having max xor value
    public int get(Trie trie, int num) {
        for (int i = 31; i >= 0; i--) {
            int bit_max = (num & (1 << i)) / (int)Math.pow(2, i);
            
            if (bit_max == 0) {
                if (trie.left != null)    trie = trie.left;
                else    trie = trie.right;
            } else {
                if (trie.right != null)    trie = trie.right;
                else    trie = trie.left;
            }
        }
        
        return trie.val;
    }
    
    
    public int findMaximumXOR(int[] nums) {
        Trie trie = new Trie(0);
        
        // Insert
        for (int num : nums) {
            insert(trie, num);
        }
        
        // Find a number in the array, make "num XOR max" has the max value
        int max_xor = 0;
        for (int num : nums) {
            int pair = get(trie, num);
            max_xor = Math.max(max_xor, num ^ pair);
        }
        
        return max_xor;
    }
}