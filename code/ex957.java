class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        if (N == 0)    return cells;
        
        // Loop in 14 days
        int n = N % 14 == 0 ? 14 : N % 14;
        for (int i = 0; i < n; i++) {
            int[] newCells = Arrays.copyOf(cells, 8);
            
            newCells[0] = 0;    newCells[7] = 0;
            for (int j = 1; j < 7; j++) {
                if (cells[j - 1] == cells[j + 1])
                    newCells[j] = 1;
                else    newCells[j] = 0;
            }
            
            cells = Arrays.copyOf(newCells, 8);
        }
        
        return cells;
    }
}