class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int nc = connections.size();
        if (nc < n - 1)    return -1;
        
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& connection : connections) {
            uni(parent, connection[0], connection[1]);
        }
        
        unordered_set<int> groups;
        for (int i = 0; i < n; i++) {
            groups.insert(find(parent, i));
        }
        
        return groups.size() - 1;
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