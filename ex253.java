class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;    if (n <= 1)    return n;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        
        PriorityQueue<Integer> rooms = new PriorityQueue<>();
        rooms.offer(intervals[0][1]);
        
        for (int i = 1; i < n; i++) {
            if (rooms.peek() > intervals[i][0])    rooms.offer(intervals[i][1]);
            else {
                rooms.poll();
                rooms.offer(intervals[i][1]);
            }
        }
        
        return rooms.size();
    }
}