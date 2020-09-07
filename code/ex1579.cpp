class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int cnt = 0, e = 0;
        
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)    parent[i] = i;
        for (auto& edge : edges) {
            int t = edge[0], a = edge[1], b = edge[2];
            if (t == 3) {
                int ra = find(parent, a), rb = find(parent, b);
                if (ra == rb)    cnt++;
                else {
                    uni(parent, ra, rb);
                    e++;
                }
            }
        }
        
        int e1 = e, e2 = e;
        vector<int> parent1 = parent;
        vector<int> parent2 = parent;
        for (auto& edge : edges) {
            int t = edge[0], a = edge[1], b = edge[2];
            if (t == 1) {
                int ra = find(parent1, a), rb = find(parent1, b);
                if (ra == rb)    cnt++;
                else {
                    uni(parent1, ra, rb);
                    e1++;
                }
            } else if (t == 2) {
                int ra = find(parent2, a), rb = find(parent2, b);
                if (ra == rb)    cnt++;
                else {
                    uni(parent2, ra, rb);
                    e2++;
                }
            }
        }
        
        return e1 == n - 1 && e2 == n - 1 ? cnt : -1;
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