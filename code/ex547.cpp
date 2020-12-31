class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uni(parent, i, j);
                }
            }
        }
        
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            set.insert(find(parent, i));
        }
        
        return set.size();
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