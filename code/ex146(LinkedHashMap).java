class LRUCache extends LinkedHashMap<Integer, Integer> {
    public int capacity = 0, cnt = 0;
    public LinkedHashMap<Integer, Integer> map;
    
    public LRUCache(int capacity) {
        map = new LinkedHashMap<Integer, Integer>(capacity, 0.75f, true) {
            protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
                return size() > capacity;
            }
        };
        this.capacity = capacity;
    }
    
    public int get(int key) {
        return map.containsKey(key) ? map.get(key) : -1;
    }
    
    public void put(int key, int value) {
        if (!map.containsKey(key))    cnt++;
        map.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */