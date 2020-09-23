class Solution {    
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9 + 7;
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; i++)
            engineers.push_back({efficiency[i], speed[i]});
        // Sort by efficiency from max to min
        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
        
        long MAX = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;    // Speed, min to max
        for (int i = 0; i < n; i++) {
            pq.push(engineers[i].second);
            sum += engineers[i].second;
            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            MAX = max(MAX, engineers[i].first * sum);
        }
        
        return (int)(MAX % mod);
    }
};