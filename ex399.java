import java.util.*;

// Define a weighted edge data structure
class Solution {
    class edge {
        String node;
        double weight;
        
        public edge(String node, double weight) {
            this.node = node;
            this.weight = weight;
        }
    }
        
    // DFS search for a path
    public double dfs(HashMap<String, List<edge>> graph, edge start, String target, double division, List<String> visited) {
        double result = -1.0;
        
        // Found the destination
        if (start.node.equals(target))    return division;
        
        visited.add(start.node);    // Update visited list
        
        for (edge e : graph.get(start.node)) {
            division *= e.weight;    // Update total division
            
            if (!visited.contains(e.node))
                result = dfs(graph, e, target, division, visited);
            
            if (result != -1.0)    return result;    // Jump out of recurrsion
            
            division /= e.weight;    // Restore division to former state
        }
        
        return -1.0;
    }
    
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        HashMap<String, List<edge>> graph = new HashMap<>();
        
        // Build graph map
        for (int i = 0; i < equations.length; i++) {
            String start = equations[i][0];
            edge end = new edge(equations[i][1], values[i]);
            
            if (graph.containsKey(start))    graph.get(start).add(end);
            else    graph.put(start, new ArrayList<edge>(Arrays.asList(end)));
            
            // Reverse edge
            String start_rev = equations[i][1];
            edge end_rev = new edge(equations[i][0], 1.0 / values[i]);
            
            if (graph.containsKey(start_rev))    graph.get(start_rev).add(end_rev);
            else    graph.put(start_rev, new ArrayList<edge>(Arrays.asList(end_rev)));
        }

        
        // DFS search
        double[] result = new double[queries.length];
        
        for (int i = 0; i < queries.length; i++) {
            double r = -1.0;
            
            if (graph.containsKey(queries[i][0])) {
                if (queries[i][0].equals(queries[i][1])) {result[i] = 1.0;    continue;}
                
                List<String> visited = new ArrayList<>();
                visited.add(queries[i][0]);
                
                for (edge e : graph.get(queries[i][0])) {
                    double division = e.weight;
                    r = dfs(graph, e, queries[i][1], division, visited);
                    if (r != -1.0)    break;
                }
            }
            result[i] = r;
        }
        
        return result;
    }
}