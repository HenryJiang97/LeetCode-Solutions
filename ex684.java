// Union-Find

class Solution {
    private int rootNode(int[] parent, int node) {
        while (node != parent[node])    node = parent[node];
        return node;
    }
    
    public int[] findRedundantConnection(int[][] edges) {
        int[] result = new int[2];
        
        int[] parent = new int[edges.length + 1];
        for (int i = 1; i <= edges.length; i++)    parent[i] = i;
        
        for (int[] edge : edges) {    
            if (rootNode(parent, edge[0]) == rootNode(parent, edge[1]))    result = edge; 
            else    parent[rootNode(parent, edge[0])] = edge[1];    // Connect root of edge[0] to edge[1];
        }
        
        return result;
    }
}