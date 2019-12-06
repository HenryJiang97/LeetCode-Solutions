class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        int c1 = costs[0], c7 = costs[1], c30 = costs[2];
        map<int, int> m;
        m[days[0]] = c1;
        
        for (int i = 1; i < n; i++) {
            int MIN = INT_MAX;
            
            // Purchase an one day pass
            auto it = --m.lower_bound(days[i]);
            MIN = min(MIN, (*it).second + c1);
            
            // Purchase a seven days pass
            it = --m.upper_bound(days[i] - 7);
            auto p = --m.end();
            while (1) {
                MIN = min(MIN, (*p).second + c7);
                if (p == m.begin() || p == it)    break;
                p--;
            }
            if (days[i] - 6 <= days[0])
                MIN = min(MIN, c7);
                
            // Purchase a thirty days pass
            it = --m.upper_bound(days[i] - 30);
            p = --m.end();
            while (1) {
                MIN = min(MIN, (*p).second + c30);
                if (p == m.begin() || p == it)    break;
                p--;
            }
            if (days[i] - 29 <= days[0])
                MIN = min(MIN, c30);
            
            m[days[i]] = MIN;
        }
        
        return m[days[n - 1]];
    }
};