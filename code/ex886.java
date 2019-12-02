class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] dislike : dislikes) {
            List<Integer> d1 = map.getOrDefault(dislike[0], new ArrayList<>());
            d1.add(dislike[1]);
            map.put(dislike[0], d1);
            List<Integer> d2 = map.getOrDefault(dislike[1], new ArrayList<>());
            d2.add(dislike[0]);
            map.put(dislike[1], d2);
        }
        
        int[] root = new int[N + 1];
        for (int i = 0; i <= N; i++)    root[i] = i;
        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
            int r = find(root, entry.getKey());
            List<Integer> list = entry.getValue();
            for (int i = 0; i < list.size(); i++) {
                if (find(root, list.get(i)) == r)    return false;
                for (int j = i + 1; j < list.size(); j++) {
                    union(root, list.get(i), list.get(j));
                }
            }
        }
        
        return true;
    }
    
    private void union(int[] root, int p1, int p2) {
        int r1 = find(root, p1), r2 = find(root, p2);
        if (r1 <= r2) {
            root[r2] = r1;
        } else {
            root[r1] = r2;
        }
    }
    
    private int find(int[] root, int p) {
        if (root[p] != p)
            root[p] = find(root, root[p]);
        return root[p];
    }
}