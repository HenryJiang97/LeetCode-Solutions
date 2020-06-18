class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> set;
        set.insert(bulbs[0]);
        for (int i = 1; i < bulbs.size(); ++i) {
            if (check(set, K, bulbs[i]))    return i + 1;
            set.insert(bulbs[i]);
        }
        return -1;
    }
    
private:
    bool check(set<int>& set, int K, int idx) {
        std::set<int>::iterator upper = set.lower_bound(idx);
        std::set<int>::iterator lower = --set.upper_bound(idx);
        
        if (upper != set.end()) {
            if (*upper - idx == K + 1)    return 1;
        }

        if (idx >= *(set.begin())) {
            if (idx - *lower == K + 1)    return 1;
        }
        return 0;
    }
};