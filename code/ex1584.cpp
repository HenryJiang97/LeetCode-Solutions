class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                pq.push({abs(x1 - x2) + abs(y1 - y2), i, j});
            }
        }
        
        int cost = 0, cnt = 0;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        while (cnt < n - 1) {
            int a = pq.top()[1], b = pq.top()[2], dis = pq.top()[0];
            pq.pop();
            if (find(parent, a) != find(parent, b)) {
                uni(parent, a, b);
                cost += dis;
                cnt++;
            }
        }
        
        return cost;
    }
    
private:
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra < rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
};