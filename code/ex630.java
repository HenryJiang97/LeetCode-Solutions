// Greedy

class Solution {
    public int scheduleCourse(int[][] courses) {
        int n = courses.length;
        
        // Sort courses by their deadline in ascending order
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        
        // Greedy to fit as much courses in the schedule as possible.
        // When meets a shorter course cannot be completed in time but can fit into the schedule if remove one existing course from the schedule, dismiss that longer course
        int timepoint = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)->b - a);    // Record course length
        
        for (int[] course : courses) {
            if (timepoint + course[0] <= course[1]) {    // Current course can fit into the schedule with no conflict
                pq.offer(course[0]);
                timepoint += course[0];
            }
            else if (!pq.isEmpty() && pq.peek() > course[0]) {    // Remove the longest course in the schedule
                // Remove the longest course in the priority queue
                int longestCourse = pq.poll();
                timepoint -= longestCourse;
                
                // Add current course to the priority queue
                timepoint += course[0];
                pq.offer(course[0]);
            }
        }
        
        return pq.size();
    }
}