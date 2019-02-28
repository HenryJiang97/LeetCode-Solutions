// BFS

import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public boolean isBipartite(int[][] graph) {
        int[] color = new int[graph.length];
        
        // Do a BFS starting at every node in the graph
        for (int i = 0; i < graph.length; i++) {
            if (color[i] != 0)    continue;
            
            Queue<Integer> queue = new LinkedList<Integer>();
            queue.offer(i);
            color[i] = 1;
            
            while (!queue.isEmpty()) {
                int out = queue.poll();
                
                for (int node : graph[out])
                    if (color[node] == 0) {
                        // The node is not visited
                        queue.offer(node);
                        color[node] = -color[out];    // Assign a different color to its parent node
                    } else {
                        // The node is visited, if it has the same color as its parent node, return false
                        if (color[node] == color[out])    return false;
                    }   
            }
        }
        
        return true;
    }
}