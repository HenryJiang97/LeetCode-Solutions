// TreeMap, store the num of opening events at certain time point

class MyCalendarTwo {
    TreeMap<Integer, Integer> map;
    
    public MyCalendarTwo() {
        map = new TreeMap<Integer, Integer>();
    }
    
    public boolean book(int start, int end) {
        // Add the current interval to the map
        map.put(start, map.getOrDefault(start, 0) + 1);
        map.put(end, map.getOrDefault(end, 0) - 1);
        
        int concurrence = 0;
        for (int key : map.keySet()) {
            concurrence += map.get(key);
            
            if (concurrence > 2) {
                // Remove the impact of current interval from the map
                map.put(start, map.get(start) - 1);
                if (map.get(start) == 0)    map.remove(start);
                map.put(end, map.get(end) + 1);
                
                return false;
            }
        }
        
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */