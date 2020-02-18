class Solution {
    public int minMalwareSpread(int[][] graph, int[] initial) {
        int n = graph.length;
        int[] parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // Union
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] == 1)
                    uni(parent, i, j);
            }
        }
        
        // Get group size
        Map<Integer, Integer> group = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            group.put(root, group.getOrDefault(root, 0) + 1);
        }
        
        int max = 0, res = -1;
        Arrays.sort(initial);
        for (int init : initial) {
            int members = group.get(find(parent ,init));
            if (members > max) {
                max = members;
                res = init;
            }
        }
        
        return res;
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