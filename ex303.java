class NumArray {
    private static int[] sum;
    public NumArray(int[] nums) {
        // Calculate the sum before a certain position and save it into an array
        sum = new int[nums.length + 1];
        sum[0] = 0;
        
        for (int i = 1; i < nums.length + 1; i++)   sum[i] = sum[i - 1] + nums[i - 1];
    }
    
    public int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
}