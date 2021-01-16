class SnapshotArray {
    vector<vector<pair<int, int>>> arr;    // Values over each snap for each idx
    int snp = 0;
public:
    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>>(length);
        for (int i = 0; i < length; i++) {
            arr[i].push_back({-1, 0});
        }
    }
    
    void set(int index, int val) {
        arr[index].push_back({snp, val});
    }
    
    int snap() {
        return snp++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>& a = arr[index];
        int lo = 0, hi = a.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (a[mid].first > snap_id)    hi = mid - 1;
            else    lo = mid;
        }
        return a[lo].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */