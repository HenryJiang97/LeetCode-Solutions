// DFS

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] edge : edges) {            
            if (ifHasCycle(map, edge[0], edge[1], edge[0]))    return edge;
            
            // Add to adjacent table
            List<Integer> list1 = map.getOrDefault(edge[0], new ArrayList<Integer>());
            list1.add(edge[1]);
            map.put(edge[0], list1);
            
            List<Integer> list2 = map.getOrDefault(edge[1], new ArrayList<Integer>());
            list2.add(edge[0]);
            map.put(edge[1], list2);
        }
        
        return new int[]{};
    }
    
    private boolean ifHasCycle(Map<Integer, List<Integer>> map, int s, int target, int pre) {
        boolean res = false;
        if (map.containsKey(s)) {
            for (int next : map.get(s)) {
                if (next == pre)    continue;
                if (next == target)    return true;
                res |= ifHasCycle(map, next, target, s);
                if (res)    return true;
            }
        }
        return res;
    }
}