// Topological ordering

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        // Corner cases
        if (n == 1)    return Arrays.asList(0);
        if (n == 2)    return Arrays.asList(0, 1);
        
        // Build a adjacent list
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            Set<Integer> list1 = adj.getOrDefault(edge[0], new HashSet<Integer>());
            Set<Integer> list2 = adj.getOrDefault(edge[1], new HashSet<Integer>());
            list1.add(edge[1]);    list2.add(edge[0]);
            adj.put(edge[0], list1);
            adj.put(edge[1], list2);
        }
        
        // Get indegree
        int[] indegree = new int[n];
        for (Map.Entry<Integer, Set<Integer>> entry : adj.entrySet()) {
            indegree[entry.getKey()] = entry.getValue().size();
        }
        
        // Go BFS
        int left = n;
        Queue<Integer> que = new LinkedList<>();
        for (int key : adj.keySet()) {
            if (indegree[key] <= 1) {
                que.offer(key);
                left--;
            }
        }

        while (left > 2) {
            for (int z = que.size(); z > 0; --z) {    // Loop through current layer
                int out = que.poll();

                for (int nei : adj.get(out)) {
                    if (indegree[nei] <= 1)    continue;    // Obsoleted node, skip
                    if (--indegree[nei] <= 1) {
                        que.offer(nei);
                        left--;
                    }
                }
            }
        }
        
        // Get result
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] > 1)    res.add(i);
        }
        
        return res;
    }
}