class RandomizedCollection {
    vector<int> vals;
    unordered_map<int, unordered_set<int>> map;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            map[val].insert(vals.size());
            vals.push_back(val);
            return false;
        }
        else {
            unordered_set<int> s;
            s.insert(vals.size());
            map[val] = s;
            vals.push_back(val);
            return true;
        }  
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end() || map[val].size() <= 0)    return false;
        
        if (val == vals.back()) {
            map[val].erase(vals.size() - 1);
            if (map[val].size() == 0)    map.erase(val);
            vals.pop_back();
            return true;
        }
        
        auto& setVal = map[val];
        int idxVal = *(setVal.begin());
        setVal.erase(idxVal);
        
        int lastVal = vals.back();
        auto& setLastVal = map[lastVal];
        setLastVal.erase(vals.size() - 1);
        
        // Swap the val with last val
        setLastVal.insert(idxVal);
        vals[idxVal] = lastVal;
        
        // Remove the last val from the vector
        vals.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int rd = rand() % vals.size();
        return vals[rd];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */