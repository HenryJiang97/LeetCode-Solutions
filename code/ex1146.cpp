class SnapshotArray {
    int len, time, snapId;
    vector<map<int,int>> arr;
    unordered_map<int, int> snap2time;
    
public:
    SnapshotArray(int length) {
        len = length;
        for (int i = 0; i < len; i++) {
            arr.push_back(map<int, int>{{0, 0}});
        }
        time = 1;    snapId = 0;
    }
    
    void set(int index, int val) {
        arr[index][time++] = val;
    }
    
    int snap() {
        snap2time[snapId] = time;
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        int t = snap2time[snap_id];
        auto& timeArr = arr[index];
        auto it = --timeArr.lower_bound(t);
        return (*it).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */