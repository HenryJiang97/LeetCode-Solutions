// Topological ordering

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int n = prerequisites.length;
        
        // Get the indegree of each course
        int[] indegree = new int[numCourses];
        for (int[] pr : prerequisites) {
            indegree[pr[0]]++;
        }
        
        // Run topological ordering
        int[] res = new int[numCourses];    int p = 0;
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)    queue.offer(i);
        }
        if (queue.isEmpty())    return new int[]{};    // No avilable entry point
        
        int visited = 0;
        while (!queue.isEmpty()) {
            int out = queue.poll();
            res[p++] = out;
            visited++;
            
            for (int i = 0; i < n; i++) {
                if (prerequisites[i][1] != out)    continue;
                
                if (--indegree[prerequisites[i][0]] == 0) {
                    queue.offer(prerequisites[i][0]);
                }
            }
        }
        if (visited != numCourses)    return new int[]{};    // Loop exists, no topological ordering available
        
        return res;
    }
}