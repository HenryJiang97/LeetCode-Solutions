class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        unordered_map<int, int> root;
        for (int i = 0; i < graph.size(); i++)    root[i] = i;
        
        // Union
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[0].size(); j++) {
                if (graph[i][j] == 1) {
                    uni(root, i, j);
                }
            }
        }
        
        // Get groups
        unordered_map<int, unordered_set<int>> group;
        for (int i = 0; i < graph.size(); i++) {
            group[find(root, i)].insert(i);
        }
        
        // Get the max group size which can be saved and get the initial to be deleted
        int MAX = -1, del = -1;
        for (auto entry : group) {
            unordered_set<int>& s = entry.second;
            int cnt = 0, d = -1;
            for (int init : initial) {
                if (s.find(init) != s.end()) {
                    cnt++;
                    d = init;
                }
            }
            
            int sz = s.size();
            if (cnt == 1) {    // Current group can be saved
                if (sz - MAX > 0) {
                    MAX = sz;
                    del = d;
                    
                } else if (s.size() - MAX == 0) {
                    del = min(del, d);
                }
            }
        }
        
        if (MAX == -1) {    // No group can be saved by removing one initial
            sort(initial.begin(), initial.end());
            return initial[0];
        } else {
            return del;
        }
    }
    
private:
    int find(unordered_map<int, int>& root, int p) {
        if (root[p] != p)
            root[p] = find(root, root[p]);
        return root[p];
    }
    
    void uni(unordered_map<int, int>& root, int a, int b) {
        int r1 = find(root, a), r2 = find(root, b);
        if (r1 <= r2)
            root[r2] = r1;
        else
            root[r1] = r2;
    }
};