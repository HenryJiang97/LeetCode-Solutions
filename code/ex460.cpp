class LFUCache {
    int cap, minFreq;
    
    unordered_map<int, int> key2value;
    unordered_map<int, int> key2freq;
    unordered_map<int, std::list<int>> freq2keylist;
    unordered_map<int, std::list<int>::iterator> key2iter;
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (key2value.find(key) == key2value.end())    return -1;
        
        refresh(key);
        
        return key2value[key];
    }
    
    void put(int key, int value) {
        if (cap <= 0)    return;
        
        if (key2value.find(key) != key2value.end())
        {
            key2value[key] = value;
            refresh(key);
        }
        else
        {
            if (key2value.size() == cap) {    // Pop out the least frequent used element
                // Pop the first element in the list
                auto& list = freq2keylist[minFreq];
                int it = list.front();
                list.pop_front();
                key2value.erase(it);
                key2freq.erase(it);
                key2iter.erase(it);
            }
            
            // Add new key-value to maps
            key2value[key] = value;
            key2freq[key] = 1;
            freq2keylist[1].push_back(key);
            key2iter[key] = --freq2keylist[1].end();
            minFreq = 1;
            return;
        }
        
    }
    
private:
    void refresh(int key) {
        int freq = key2freq[key];
        auto& list = freq2keylist[freq];
        auto& it = key2iter[key];
        
        // Update hash maps
        list.erase(it);
        freq2keylist[++freq].push_back(key);
        key2freq[key]++;
        key2iter[key] = --freq2keylist[freq].end();
        
        // Increase minFreq
        if (freq2keylist[minFreq].size() == 0) {
            minFreq++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */