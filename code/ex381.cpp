class RandomizedCollection {
    vector<int> arr;    // Every number
    unordered_map<int, unordered_set<int>> map;    // {val, {idxs}}
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val) == 0) {
            map[val].insert(arr.size());
            arr.push_back(val);
            return 1;
        } else {
            map[val].insert(arr.size());
            arr.push_back(val);
            return 0;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        int n = arr.size();
        if (map.count(val) == 0)    return 0;
        
        // If the last element == val, remove it
        if (arr.back() == val) {
            map[val].erase(n - 1);
            if (map[val].empty())    map.erase(val);
            arr.pop_back();
            return 1;
        }
        
        // Swap arr[idx] with arr[n - 1]
        int idx = *map[val].begin();
        int endVal = arr[n - 1];    // Last element in the array
        
        map[endVal].erase(n - 1);
        map[endVal].insert(idx);
        map[val].erase(idx);
        if (map[val].empty())    map.erase(val);
        arr[idx] = endVal;
        arr[n - 1] = val;
        
        // Delete last element
        arr.pop_back();
        
        return 1;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */