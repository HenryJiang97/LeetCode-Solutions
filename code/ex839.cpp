// Union Find

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {        
        int n = A.size();
        vector<int> parent;
        parent.resize(n);
        for (int i = 0; i < n; i++)    parent[i] = i;
        
        // Union
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ifConnect(A[i], A[j])) {
                    uni(parent, i, j);
                }
            }
        }
        
        // Find group
        unordered_set<int> root;
        for (int i = 0; i < n; i++) {
            root.insert(find(parent, i));
        }
        
        return root.size();
    }
    
private:
    int find(vector<int>& parent, int p) {
        if (parent[p] != p)
            parent[p] = find(parent, parent[p]);
        return parent[p];
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int r1 = find(parent, a), r2 = find(parent, b);
        if (r1 <= r2)    parent[r2] = r1;
        else    parent[r1] = r2;
    }
    
    bool ifConnect(string a, string b) {
        if (a == b)    return true;
        if (a.length() != b.length())    return false;
        
        int cnt = 0, n = a.length();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (++cnt > 2)    return false;
            }
        }
        
        return cnt == 2;
    }
};