class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> arr;
        for (int i = 0; i < quality.size(); i++)
            arr.push_back({(double)wage[i] / quality[i], quality[i]});
        sort(arr.begin(), arr.end());
        
        priority_queue<int> pq;
        double MIN = INT_MAX;
        int qsum = 0;
        for (auto& p : arr) {
            qsum += p.second;
            pq.push(p.second);
            while (pq.size() > K) {
                qsum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K)
                MIN = min(MIN, (double)qsum * p.first);
        }
        
        return MIN;
    }
};