// O(n^2)

class Solution {
    public int minSwapsCouples(int[] row) {
        int swap = 0;
        
        for (int i = 0; i < row.length - 1; i += 2) {
            int first = row[i];
            int second = (first % 2 == 0) ? first + 1 : first - 1;
            
            if (row[i + 1] == second)    continue;
            
            for (int j = i + 2; j < row.length; j++) {
                if (row[j] == second) {
                    // Swap two people (row[i + 1] and row[j])
                    int temp = row[j];
                    row[j] = row[i + 1];
                    row[i + 1] = temp;
                    
                    swap++;
                }
            }
        }
        
        return swap;
    }
}