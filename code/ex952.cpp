class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        
        // Get a list of idxs for each possible factor
        unordered_map<int, vector<int>> factor2idx;
        for (int i = 0; i < n; i++) {
            int a = A[i];
            factor2idx[a].push_back(i);
            for (int f = 2; f <= sqrt(a); f++) {
                if (a % f == 0) {
                    factor2idx[f].push_back(i);
                    factor2idx[a / f].push_back(i);
                }
            }
        }
        
        // Union
        vector<int> parent(n);
        for (int i = 0; i < n; i++)    parent[i] = i;
        for (auto& [f, idx] : factor2idx) {
            for (int i = 0; i < idx.size() - 1; i++) {
                uni(parent, idx[i], idx[i + 1]);
            }
        }
        
        // Get result
        int MAX = 0;
        unordered_map<int, int> groups;
        for (int i = 0; i < n; i++) {
            MAX = max(MAX, ++groups[find(parent, i)]);
        }
        
        return MAX;
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