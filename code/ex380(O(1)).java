class RandomizedSet {
    
    private Map<Integer, Integer> map;    // Val-id pair
    private List<Integer> vals;    // Save all values to a list
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        map = new HashMap<Integer, Integer>();
        vals = new ArrayList<Integer>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (map.containsKey(val))    return false;
        
        // Add the value into the list / Add the value into map (k, id)
        map.put(val, vals.size());
        vals.add(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val))    return false;
        
        // Swap ids corresponding to last_val and val in the map
        int last_val = vals.get(vals.size() - 1);
        map.put(last_val, map.get(val));
        
        // Swap last_val with val in the vals list
        vals.set(map.get(last_val), last_val);
        
        map.remove(val);
        vals.remove(vals.size() - 1);
        
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int idx = rand.nextInt(vals.size());
        return vals.get(idx);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */