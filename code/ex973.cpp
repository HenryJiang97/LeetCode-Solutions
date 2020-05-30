struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (auto& point : points) {
            pq.push(point);
            if (pq.size() > K)    pq.pop();
        }
        
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};