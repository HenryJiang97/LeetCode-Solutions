class Solution {
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] != b[0])    return a[0] > b[0];
            else    return a[2] > b[2];    // Choose smaller bike index
        }
    };
    
    struct cmp2 {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] != b[0])    return a[0] > b[0];
            else if (a[1] != b[1])    return a[1] > b[1];    // Choose smaller worker index
            else    return a[2] > b[2];    // Choose smaller bike index
        }
    };
    
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nw = workers.size(), nb = bikes.size();
        
        // Build an priority queue array to store the distance between each worker and bike
        vector<priority_queue<vector<int>, vector<vector<int>>, cmp>> pqvec(nw);
        for (int i = 0; i < nw; i++) {
            priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
            
            for (int j = 0; j < nb; j++) {
                pq.push({abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]), i, j});
            }
            
            pqvec[i] = pq;
        }
        
        vector<int> w2b(nw, -1), b2w(nb, -1);    // Pair workers and bikes
        
        priority_queue<vector<int>, vector<vector<int>>, cmp2> pq;
        for (int i = 0; i < nw; i++) {
            pq.push(pqvec[i].top());
            pqvec[i].pop();
        }
        
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            
            if (b2w[out[2]] == -1) {    // If the bike is still available
                w2b[out[1]] = out[2];
                b2w[out[2]] = out[1];
            }
            else {
                vector<int> v = pqvec[out[1]].top();
                pq.push(v);
                pqvec[out[1]].pop();
            }
        }
        
        return w2b;
    }
};