// Heap

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        int endurance = startFuel;
        int cnt = 0;
        priority_queue<int> pq;
        
        for (int i = 0; i < n; i++) {
            if (endurance >= stations[i][0]) {
                pq.push(stations[i][1]);
            } else {
                if (pq.empty())    return -1;
                
                int out = pq.top();    pq.pop();
                endurance += out;
                cnt++;    i--;
            }
        }
        
        // Deal with end part of distance
        while (!pq.empty() && endurance < target) {
            endurance += pq.top();    pq.pop();
            cnt++;
        }
        
        if (endurance < target)    return -1;
        
        return cnt;
    }
};