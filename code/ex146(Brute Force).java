class LRUCache {
    public int capacity = 0, cnt = 0;
    public Deque<Integer> deque;
    public Map<Integer, Integer> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        deque = new LinkedList<Integer>();
        map = new HashMap<Integer, Integer>();
    }
    
    public int get(int key) {
        if (!map.containsKey(key))    return -1;
        
        // Update deque
        moveFront(key);
        
        return map.get(key);
    }
    
    public void put(int key, int value) {
        cnt += map.containsKey(key) ? 0 : 1;
        
        // Update deque
        if (map.containsKey(key)) {
            moveFront(key); 
        } else {
            deque.push(key);
            if (cnt > capacity) {
                map.remove(deque.pollLast());
                cnt--;
            }
        }  
        
        // Update map
        map.put(key, value);
    }
    
    private void moveFront(int key) {
        Stack<Integer> temp = new Stack<>();
        while (true) {
            if (deque.peekFirst() == key) {
                deque.pollFirst();
                break;
            } else {
                temp.push(deque.pollFirst());
            }
        }
        
        while (!temp.isEmpty())    deque.push(temp.pop());
        
        deque.push(key);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */