class Solution {
    public int[] distributeCandies(int can, int n) {
        int[] res = new int[n];
        int start = 1, sum = 0, row = 0;
        
        // Get the number of rounds of people which has been distributed full amount of candies
        while (sum + cntRowSum(start, n) <= can) {
            sum += cntRowSum(start, n);
            start += n;
            row++;
        }
        
        // Calculate the first row rounds for each person
        for (int i = 0; i < n; i++)
            res[i] = (2 * i + 2 + n * (row - 1)) * row / 2;
        
        // Calculate the candies given to each person for the last round
        can -= sum;
        for (int i = 0; i < n && can > 0; i++) {
            res[i] += Math.min(start, can);
            can -= Math.min(start, can);
            start++;
        }
        
        return res;
    }
    
    private int cntRowSum(int start, int n) {
        return (2 * start + n - 1) * n / 2;
    }
}