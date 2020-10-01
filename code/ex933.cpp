class RecentCounter {
    vector<int> pings;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push_back(t);
        int start = t - 3000;
        return distance(lower_bound(pings.begin(), pings.end(), start), prev(pings.end())) + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */