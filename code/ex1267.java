class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] parent = new int[m * n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                parent[i * n + j] = i * n + j;
        
        // Each row
        for (int i = 0; i < m; i++) {
            int first = 0;
            while (first < n && grid[i][first] == 0)    first++;
            for (int j = first + 1; j < n; j++)
                if (grid[i][j] == 1)
                    uni(parent, i * n + first, i * n + j);
        }
        
        // Each col
        for (int j = 0; j < n; j++) {
            int first = 0;
            while (first < m && grid[first][j] == 0)    first++;
            for (int i = first + 1; i < m; i++)
                if (grid[i][j] == 1)
                    uni(parent, first * n + j, i * n + j);
        }
        
        // Get groups
        Map<Integer, Integer> groups = new HashMap<>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    int root = find(parent, i * n + j);
                    groups.put(root, groups.getOrDefault(root, 0) + 1);
                }
        
        int cnt = 0;
        for (Map.Entry<Integer, Integer> entry : groups.entrySet())
            if (entry.getValue() > 1)    cnt += entry.getValue();
        
        return cnt;
    }
    
    private void uni(int[] parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    private int find(int[] parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
}