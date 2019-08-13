// TreeMap

class TimeMap {
    // TreeMap => {timestamp, value}
    HashMap<String, TreeMap<Integer, String>> map; 

    /** Initialize your data structure here. */
    public TimeMap() {
        map = new HashMap<String, TreeMap<Integer, String>>();
    }
    
    public void set(String key, String value, int timestamp) {
        TreeMap<Integer, String> treemap = map.getOrDefault(key, new TreeMap<Integer, String>());
        treemap.put(timestamp, value);
        map.put(key, treemap);
    }
    
    public String get(String key, int timestamp) {
        TreeMap<Integer, String> treemap = map.get(key);
        
        Integer k = treemap.floorKey(timestamp);
        return k == null ? "" : treemap.get(k);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */