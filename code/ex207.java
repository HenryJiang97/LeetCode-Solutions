// Topological ordering

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int n = prerequisites.length;
        
        // Get the indegree of each course
        int[] indegree = new int[numCourses];
        for (int[] pr : prerequisites) {
            indegree[pr[1]]++;
        }
        
        // Run topological ordering
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)    queue.offer(i);
        }
        if (queue.isEmpty())    return false;
        
        int visited = 0;
        while (!queue.isEmpty()) {
            int out = queue.poll();
            visited++;
            
            for (int i = 0; i < n; i++) {
                if (prerequisites[i][0] != out)    continue;
                
                if (--indegree[prerequisites[i][1]] == 0) {
                    queue.offer(prerequisites[i][1]);
                }
            }
        }
        
        return visited == numCourses;
    }
}