class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        
        // Build root array
        int[] root = new int[n];
        for (int i = 0; i < n; i++)    root[i] = i;
        
        // Union
        for (List<Integer> pair : pairs) {
            int r1 = find(root, pair.get(0)), r2 = find(root, pair.get(1));
            union(root, r1, r2);
        }
        
        // Group chars
        Map<Integer, PriorityQueue<Character>> root2char = new HashMap();
        for (int i = 0; i < n; i++) {
            int r = find(root, i);
            PriorityQueue<Character> ch = root2char.getOrDefault(r, new PriorityQueue<Character>());
            ch.offer(s.charAt(i));
            root2char.put(r, ch);
        }
        
        // Reorder the original string
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < n; i++) {
            int r = find(root, i);
            sb.setCharAt(i, root2char.get(r).poll());
        }
        
        return sb.toString(); 
    }
    
    private int find(int[] root, int p) {
        if (root[p] != p)    root[p] = find(root, root[p]);
        return root[p];
    }
    
    private void union(int[] root, int a, int b) {
        root[b] = a;
    }
}