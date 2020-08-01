class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        
        vector<int> parent(n);
        for (int i = 0; i < n; i++)    parent[i] = i;
        
        unordered_map<int, int> fac2idx;    // Factor to index
        for (int i = 0; i < n; i++) {
            for (int f = 2; f * f <= A[i]; f++) {    // Factor candidates of A[i]
                if (A[i] % f == 0) {
                    if (fac2idx.count(f) > 0)    uni(parent, fac2idx[f], i);
                    else    fac2idx[f] = i;
                        
                    if (fac2idx.count(A[i] / f) > 0)    uni(parent, fac2idx[A[i] / f], i);
                    else    fac2idx[A[i] / f] = i;
                }
            }
            // Be a factor itself
            if (fac2idx.count(A[i]) == 0)    fac2idx[A[i]] = i;
            else    uni(parent, fac2idx[A[i]], i);
        }
        
        int MAX = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
            MAX = max(MAX, ++cnt[find(parent, i)]);
        
        return MAX;
    }
    
private:
    int GCD(int a, int b) {
        if (b == 0)    return a;
        return GCD(b, a % b);
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
};