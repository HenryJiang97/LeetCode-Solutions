class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {return a[2] < b[2];});
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
            q.push_back(queries[i]);
        }
        sort(q.begin(), q.end(), [](vector<int>& a, vector<int>& b) {return a[2] < b[2];});
        
        int i = 0;
        vector<bool> res(queries.size());
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& query : q) {
            int start = query[0], end = query[1], limit = query[2], idx = query[3];
            // Union
            while (i < edgeList.size() && edgeList[i][2] < limit) {
                if (find(parent, edgeList[i][0]) != find(parent, edgeList[i][1]))
                    uni(parent, edgeList[i][0], edgeList[i][1]);
                i++;
            }
            // Find
            res[idx] = find(parent, start) == find(parent, end);
        }
        
        return res;
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