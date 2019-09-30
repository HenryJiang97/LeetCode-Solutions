// Union find

class Solution {
    public int findCircleNum(int[][] M) {
        int n = M.length;
        
        // Define root list for the union find process
        int[] root = new int[n];
        for (int i = 0; i < n; i++)    root[i] = i;
        
        // Union
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && find(root, i) != find(root, j))
                    union(root, i, j);
            }
        }
        
        // Get friend circles
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            root[i] = find(root, i);
            set.add(root[i]);
        }
        return set.size();
    }
    
    private int find(int[] root, int p) {
        if (root[p] != p)
            p = find(root, root[p]);
        return p;
    }
    
    private void union(int[] root, int n1, int n2) {
        int r1 = find(root, n1), r2 = find(root, n2);
        if (r1 < r2)    root[r2] = r1;
        else    root[r1] = r2;
    }
}