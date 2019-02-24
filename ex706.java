import java.util.ArrayList;

class MyHashMap {
    public class kvPair {
        int key, value;
        public kvPair(int k, int v) {key = k; value = v;}
    }
    
    private ArrayList<kvPair> list;

    
    /** Initialize your data structure here. */
    public MyHashMap() {
        list = new ArrayList<kvPair>();
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        int sign = 0;
        
        for (kvPair pair : list)
            if (pair.key == key) {sign = 1; pair.value = value;}
        
        if (sign == 0)    list.add(new kvPair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        for (kvPair pair : list)
            if (pair.key == key)    return pair.value;
    
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        for (int i = 0; i < list.size(); i++)
            if (list.get(i).key == key)    list.remove(i);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */