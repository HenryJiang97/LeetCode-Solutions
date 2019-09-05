// Linked HashTable Implementation

public class llNode {    // Define a linked list data structure
    int key;
    int val;
    llNode next = null, prev = null;
    public llNode(int _key, int _val) {
        key = _key;
        val = _val;
    }
}

class LRUCache {
    public Map<Integer, llNode> map = new HashMap<>();
    public int capacity, cap = 0;
    public llNode head, end;
    
    public LRUCache(int capacity) {
        head = new llNode(0, 0);
        end = new llNode(0, 0);
        head.next = end;    end.prev = head;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!map.containsKey(key))    return -1;
        llNode node = map.get(key);
        
        // Move the node to the head of the linkedlist
        remove(node);    add(node);
        
        return node.val;
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            llNode node = map.get(key);
            node.val = value;
            
            // Move the existing node to the front of the linkedlist
            remove(node);    add(node);
        }
        else {
            llNode node = new llNode(key, value);
            map.put(key, node);
            add(node);
            cap++;
            
            if (cap > capacity) {
                // Delete the least recently used node
                map.remove(end.prev.key);
                remove(end.prev);
                cap--;
            }
        }
    }
    
    private void remove(llNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    
    private void add(llNode node) {
        node.next = head.next;
        head.next = node;
        node.prev = head;
        node.next.prev = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */