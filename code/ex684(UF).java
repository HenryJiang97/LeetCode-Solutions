// Union find

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int[] root = new int[2001];
        for (int i = 1; i <= 2000; i++)    root[i] = i;
        
        for (int[] edge : edges) {
            int root0 = find(root, edge[0]), root1 = find(root, edge[1]);
            if (root0 == root1)    return edge;
            union(root, root0, root1);
        }
        
        return new int[]{};
    }
    
    private int find(int[] root, int n) {
        int p = n;
        if (root[p] != p) {
            p = find(root, root[p]);
        }
        return p;
    }
    
    private void union(int[] root, int a, int b) {
        root[a] = b;
    }
}