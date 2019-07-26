class NumArray {
    int [] sum_tree;
    
    public NumArray(int[] nums) {
        if (nums.length == 0)   sum_tree = new int[1];
        else {
            // Build a segmented tree
            sum_tree = new int[nums.length * 2];
        
            for (int i = nums.length, j = 0; i < sum_tree.length; i++, j++)    sum_tree[i] = nums[j];
            for (int i = nums.length - 1; i >= 1; i--)    sum_tree[i] = sum_tree[i * 2] + sum_tree[i * 2 + 1];
            
        }
        
    }
    
    public void update(int i, int val) {
        int diff = val - sum_tree[sum_tree.length / 2 + i];
        // Set the leaf value to the updated value
        sum_tree[sum_tree.length / 2 + i] = val;
        
        // Deal with parents nodes
        int start = (sum_tree.length / 2 + i) / 2;
        
        for (int j = start; j > 0; j /= 2)    sum_tree[j] += diff;
    }
    
    public int sumRange(int i, int j) {
        
        int sum = 0;
        
        i += sum_tree.length / 2;
        j += sum_tree.length / 2;
        
        while (i <= j) {
            if (i % 2 != 0) {
                sum += sum_tree[i];
                i++;
            }
            
            if (j % 2 == 0) {
                sum += sum_tree[j];
                j--;
            }
            
            i /= 2;
            j /= 2;
        }
        
        return sum;
    }
}