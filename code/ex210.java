// Topological Sort

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private int time;
    
    private boolean dfs(HashMap<Integer, ArrayList<Integer>> adj, int root, int[] color, int[] finish) {       
        if (!adj.containsKey(root))    {color[root] = 2;    finish[root] = ++time;    return true;}
        
        for (int neighbor : adj.get(root)) {
            if (color[neighbor] == 0) {
                time++;
                // Mark the node to grey
                color[neighbor] = 1;
                // DFS
                boolean r = dfs(adj, neighbor, color, finish);
                if (!r)    return false;
            } else if (color[neighbor] == 1)    return false;
        }
        
        // Mark the node to black
        color[root] = 2;
        
        // Record the finishing time
        finish[root] = ++time;
        
        return true;
    }
    
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // Build adjacent table
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for (int[] p : prerequisites) {
            if (adj.containsKey(p[1]))    adj.get(p[1]).add(p[0]);
            else    adj.put(p[1], new ArrayList<Integer>(Arrays.asList(p[0])));
        }
        
        // 0 -> white; 1 -> grey; 2 -> black
        int[] color = new int[numCourses];
        // finish array to record the final time of each node
        int[] finish = new int[numCourses];
        // Keep track of the visiting and finishing time
        time = 0;
        
        // DFS
        for (int root = 0; root < numCourses; root++) {
            // If the root in the forest which has not been visited and has no neighbor
            if (!adj.containsKey(root) && color[root] == 0)    {color[root] = 2;    finish[root] = ++time;    continue;}        
            // If the root in the forest has not been visited
            else if (color[root] == 0) {
                time++;
                color[root] = 1;
                // DFS
                if (!dfs(adj, root, color, finish))    return new int[0];
            }
        }
        
        
        // Get result (Sort the finishing time from high to low and return their index sequence)
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < numCourses; i++) {
            finish[i] = 2 * numCourses - finish[i];
            map.put(finish[i], i);
        }
        
        Arrays.sort(finish);
        
        int[] result = new int[numCourses];
        int j = 0;
        for (int i = 0; i < numCourses * 2; i++) {
            if (map.containsKey(i))    result[j++] = map.get(i);
        }

            
        return result;
    }
}