class DistanceLimitedPathsExist {
    int n;
    vector<vector<pair<int, int>>> snapshot;
    
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        this->n = n;
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        // Build snapshot array and init
        snapshot = vector<vector<pair<int, int>>>(n);    // {limit, val}
        for (int i = 0; i < n; i++) {
            snapshot[i].push_back({0, i});
        }
        
        // Union find and save snapshots
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < edgeList.size(); i++) {
            vector<int>& e = edgeList[i];
            int a = e[0], b = e[1], dis = e[2];
            uni(parent, a, b, dis);
        }
    }
    
    bool query(int p, int q, int limit) {
        return queryFind(p, limit) == queryFind(q, limit);
    }
    
private:
    int findSnap(vector<pair<int, int>>& ss, int limit) {
        int lo = 0, hi = ss.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (ss[mid].first >= limit)    hi = mid - 1;
            else    lo = mid;
        }
        return ss[lo].second;
    }
    
    int queryFind(int a, int limit) {
        int parent = findSnap(snapshot[a], limit);
        if (parent != a)
            parent = queryFind(parent, limit);
        return parent;
    }
    
    // Standard Union Find
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }

    void uni(vector<int>& parent, int a, int b, int dis) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra < rb) {
            parent[rb] = ra;
            snapshot[rb].push_back({dis, ra});
        } else {
            parent[ra] = rb;
            snapshot[ra].push_back({dis, rb});
        }
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */