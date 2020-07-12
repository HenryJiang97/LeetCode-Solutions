class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        
        unordered_map<int, int> lastRainy;    // The last rainy day on a lake
        set<int> sunny;    // An ordered set for sunny days before ith day
        
        for (int i = 0; i < n; i++) {
            if (rains[i] != 0) {    // Rainy day
                res[i] = -1;
                if (lastRainy.count(rains[i]) == 0) {
                    lastRainy[rains[i]] = i;
                    continue;
                }
                
                // Find a sunny day after last rainy day for current lake
                int lastDay = lastRainy[rains[i]];
                set<int>::iterator it = sunny.upper_bound(lastDay);
                if (it == sunny.end())    return {};    // Cannot find a sunny day between two rainy days
                res[*it] = rains[i];
                sunny.erase(*it);
                
                lastRainy[rains[i]] = i;
            } else {    // Sunny day
                sunny.insert(i);
            }
        }
        
        return res;
    }
};