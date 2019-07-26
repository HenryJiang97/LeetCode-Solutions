class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        int[] min = new int[n];
        
        for (int i = 0; i < n; i++) {
            String[] time = timePoints.get(i).split(":");
            min[i] = 60 * Integer.parseInt(time[0]) + Integer.parseInt(time[1]);
        }
        
        int minimum = 1440;
        Arrays.sort(min);
        for (int i = 1; i < n; i++) {
            minimum = Math.min(minimum, min[i] - min[i - 1]);
        }
        
        return Math.min(minimum, min[0] + 1440 - min[n - 1]);
    }
}