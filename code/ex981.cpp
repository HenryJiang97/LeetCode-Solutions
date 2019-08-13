// Binary search

typedef pair<int, string> is;

class TimeMap {
    unordered_map<string, vector<is>> map;    // {key : {(timestamp1, value1), (timestamp2, value2)}}
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<is>& arr = map[key];
        int n = arr.size();
        
        if (timestamp >= arr[n - 1].first)    return arr[n - 1].second;
        
        // Binary search for certain timestamp
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid].first == timestamp)    return arr[mid].second;
            else if (arr[mid].first < timestamp)    lo = mid + 1;
            else {
                if (mid - 1 >= 0 && arr[mid - 1].first < timestamp)
                    return arr[mid - 1].second;
                hi = mid - 1;
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */