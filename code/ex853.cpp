class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();    if (n == 0)    return 0;
        
        // Sort the position-speed pair by position in ascending order
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({position[i], speed[i]});
        }
        sort(p.begin(), p.end());
        
        // Find fleets
        int cnt = 0;
        double base = (double)(target - p[n - 1].first) / p[n - 1].second;
        for (int i = n - 2; i >= 0; i--) {
            double cur = (double)(target - p[i].first) / p[i].second;
            if (cur > base) {
                cnt++;
                base = cur;
            }
        }
        
        return cnt + 1;
    }
};