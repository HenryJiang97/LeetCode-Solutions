// Segment Tree

class NumArray {
    public int[] segTree;    // Define a segment tree
    public int n;
    
    public NumArray(int[] nums) {
        n = nums.length;
        segTree = new int[n * 2];
        buildTree(nums);
    }
    
    private void buildTree(int[] nums) {
        // Base case, build leaves: [n : 2 * n - 1]
        for (int i = 0; i < n; i++)
            segTree[i + n] = nums[i];
        
        // Build roots: [1 : n - 1]
        for (int i = n - 1; i > 0; --i)
            segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
    }
    
    public void update(int i, int val) {
        i += n;
        segTree[i] = val;
        i = i % 2 == 0 ? i / 2 : (i - 1) / 2;
        
        while (i > 0) {    // Update every element on this branch
            segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
            i = i % 2 == 0 ? i / 2 : (i - 1) / 2;
        }
    }
    
    public int sumRange(int i, int j) {
        i += n;    j += n;
        
        int sum = 0;
        while (i <= j) {    // Track up the tree for sum
            if (i % 2 != 0) {
                sum += segTree[i];
                i++;
            }
            
            if (j % 2 == 0) {
                sum += segTree[j];
                j--;
            }
            
            i /= 2;    j /= 2;
        }
        
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */