class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m = houses.size(), n = heaters.size();
        if (m == 0)    return 0;
        if (n == 0)    return INT_MAX;
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
    
        int p = 0, MAX = 0;
        for (int i = 0; i < m; i++) {
            while (p + 1 < n && abs(houses[i] - heaters[p]) >= abs(houses[i] - heaters[p + 1]))
                p++;
            MAX = max(MAX, abs(houses[i] - heaters[p]));
        }
        
        return MAX;
    }
};