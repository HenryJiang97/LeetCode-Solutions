class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1)    return -1; 
        
        int[] parent = new int[n];
        for (int i = 0; i < n; i++)    parent[i] = i;
        
        // Union
        for (int[] connection : connections)
            uni(parent, connection[0], connection[1]);
        
        // Find groups
        Set<Integer> groups = new HashSet<>();
        for (int i = 0; i < n; i++)
            groups.add(find(parent, i));
        
        return groups.size() - 1;
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