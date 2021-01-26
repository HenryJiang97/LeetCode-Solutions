class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        int connected = 0;
        for (auto& edge : edges) {
            int a = edge[1], b = edge[2], type = edge[0];
            if (type != 3)    continue;
            if (find(parent, a) == find(parent, b))    cnt++;
            else {
                uni(parent, a, b);
                connected++;
            }
        }
        
        vector<int> parent1 = parent;
        vector<int> parent2 = parent;
        int connected1 = connected, connected2 = connected;
        for (auto& edge : edges) {
            int a = edge[1], b = edge[2], type = edge[0];
            if (type == 1) {
                if (find(parent1, a) == find(parent1, b))    cnt++;
                else {
                    uni(parent1, a, b);
                    connected1++;
                }
            } else if (type == 2) {
                if (find(parent2, a) == find(parent2, b))    cnt++;
                else {
                    uni(parent2, a, b);
                    connected2++;
                }
            }
        }
        
        return connected1 == n - 1 && connected2 == n - 1 ? cnt : -1;
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