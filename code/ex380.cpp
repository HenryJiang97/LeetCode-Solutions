class RandomizedSet {
    unordered_map<int, int> val2id;
    unordered_map<int, int> id2val;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val2id.count(val) > 0)    return 0;
        int id = val2id.size();
        val2id[val] = id;
        id2val[id] = val;
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val2id.count(val) == 0)    return 0;
        int id = val2id[val];
        val2id.erase(val);
        id2val.erase(id);
        // Swap the last id item with the empty space
        int lastId = val2id.size();
        if (lastId == 0)    return 1;
        int lastVal = id2val[lastId];
        val2id.erase(lastVal);
        id2val.erase(lastId);
        val2id[lastVal] = id;
        id2val[id] = lastVal;
        return 1;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = val2id.size();
        int r = rand() % size;
        return id2val[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */