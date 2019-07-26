// Test if the graph is DAC

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private boolean dfs(HashMap<Integer, ArrayList<Integer>> adj, int root, int[] color) {       
        if (!adj.containsKey(root))    {color[root] = 2;    return true;}
        
        for (int neighbor : adj.get(root)) {
            if (color[neighbor] == 0) {
                // Mark the node to grey
                color[neighbor] = 1;
                // DFS
                boolean r = dfs(adj, neighbor, color);
                if (!r)    return false;
            } else if (color[neighbor] == 1)    return false;
        }
        
        // Mark the node to black
        color[root] = 2;
        
        return true;
    }
    

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // Build adjacent table
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for (int[] p : prerequisites) {
            if (adj.containsKey(p[1]))    adj.get(p[1]).add(p[0]);
            else    adj.put(p[1], new ArrayList<Integer>(Arrays.asList(p[0])));
        }
        
        // 0 -> white; 1 -> grey; 2 -> black
        int[] color = new int[numCourses];
        
        // DFS
        for (int key : adj.keySet()) {
            if (color[key] == 0) {
                color[key] = 1;    // Mark the node to grey
                // DFS
                if (!dfs(adj, key, color))    return false;
            }
        }
        
        return true;
    }
}