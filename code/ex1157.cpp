class MajorityChecker {
    unordered_map<int, vector<int>> val2idx;
    vector<pair<int, int>> cnt2val;
public:
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            val2idx[arr[i]].push_back(i);
        }
        
        for (auto entry : val2idx) {
            cnt2val.push_back({entry.second.size(), entry.first});
        }
        
        sort(cnt2val.begin(), cnt2val.end(), greater<pair<int, int>>());
    }
    
    int query(int left, int right, int threshold) {
        int remain = right - left + 1;    // Remaining indexes inside interval [left, right]
        
        for (auto p : cnt2val) {
            int val = p.second;
            vector<int>& idx = val2idx[val];
            
            // Binary search to find indexes falling into section [left, right]
            auto lo = lower_bound(idx.begin(), idx.end(), left);
            auto hi = upper_bound(idx.begin(), idx.end(), right) - 1;
            int interval = hi - lo + 1;
            if (interval >= threshold)
                return val;
            else
                remain -= interval;
            
            if (remain < threshold)    return -1;
        }
        
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */