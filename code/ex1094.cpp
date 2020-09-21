class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> road(1002);
        for (auto& trip : trips) {
            int passengers = trip[0], start = trip[1], end = trip[2];
            road[start] += passengers;
            road[end] -= passengers;
        }
        for (int i = 1; i <= 1000; i++) {
            road[i] += road[i - 1];
            if (road[i] > capacity)    return 0;
        }
        return 1;
    }
};