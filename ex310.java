import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;

class Solution {
    // Get the max height under a root
    public static int height(HashMap<Integer, ArrayList<Integer>> map, int root, int leaf) {
        int max = 0;

        for (int a : map.get(leaf))
            if (a != root)    max = Math.max(height(map, leaf, a) + 1, max);
        
        return max;
    }
    
    
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        
        // Init map
        for (int i = 0; i < n; ++i)    map.put(i, new ArrayList<Integer>());
        
        // Create adjacency list
        ArrayList<Integer> a, b;
        for (int[] arr : edges) {
            a = new ArrayList<Integer>(map.get(arr[0]));
            b = new ArrayList<Integer>(map.get(arr[1]));
            a.add(arr[1]);    b.add(arr[0]);
            
            map.put(arr[0], a);
            map.put(arr[1], b);
        }
        
        
        //Find MHT and find out result
        int max = 0;
        int min = Integer.MAX_VALUE;
        List<Integer> r = new ArrayList<>();
        
        for (int i = 0; i < n; ++i) {
            for (int j : map.get(i))
                max = Math.max(height(map, i,j) + 1, max);
        
            // Add result to r list
            if (max < min) {
                r.clear();
                r.add(i);
                min = max;
            } else if (max == min)
                r.add(i);
            
            max = 0;
        }

        
        return r;
    }
}