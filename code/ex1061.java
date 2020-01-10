class Solution {
    public String smallestEquivalentString(String A, String B, String S) {
        int n = A.length(), ns = S.length();
        int[] parent = new int[26];
        for (int i = 0; i < 26; i++)    parent[i] = i;
        for (int i = 0; i < n; i++) {
            union(parent, A.charAt(i) - 'a', B.charAt(i) - 'a');
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < ns; i++) {
            int par = find(parent, S.charAt(i) - 'a');
            sb.append((char)(par + 'a'));
        }  
        
        return sb.toString();
    }
    
    // Helper methods
    private void union(int[] parent, int a, int b) {
        int pa = find(parent, a), pb = find(parent, b);
        if (pa <= pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }
    
    private int find(int[] parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
}