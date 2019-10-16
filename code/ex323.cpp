class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++)    parent[i] = i;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            uni(parent, u, v);
        }
        
        unordered_set<int> set;
        for (int p : parent)
            set.insert(find(parent, p));
        
        return set.size();
    }
    
private:
    int find(vector<int>& parent, int p) {
        if (parent[p] != p)
            parent[p] = find(parent, parent[p]);
        return parent[p];
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)
            parent[rb] = ra;
        else
            parent[ra] = rb;
    }
};