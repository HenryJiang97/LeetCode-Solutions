class HitCounter {
    deque<pair<int, int>> dque;
    int inque = 0;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (!dque.empty() && dque.back().first == timestamp) {
            pair<int, int> out = dque.back();    dque.pop_back();
            dque.push_back({timestamp, out.second + 1});
        } else {
            dque.push_back({timestamp, 1});
        }
        inque++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!dque.empty() && timestamp - dque.front().first >= 5 * 60) {
            inque -= dque.front().second;
            dque.pop_front();
        }
        return inque;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */