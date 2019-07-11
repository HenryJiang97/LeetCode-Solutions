class MyCalendar {
    public TreeMap<Integer, Integer> map;
        
    public MyCalendar() {
        map = new TreeMap<Integer, Integer>();
    }
    
    public boolean book(int start, int end) {
        // Find the confliction to the left of the new interval
        Integer floor = map.floorKey(start);
        if (floor != null && map.get(floor) > start)    return false;
        
        // Find the confliction to the right of the new interval
        Integer ceiling = map.ceilingKey(start);
        if (ceiling != null && end > ceiling)    return false;
        
        map.put(start, end);
        
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */