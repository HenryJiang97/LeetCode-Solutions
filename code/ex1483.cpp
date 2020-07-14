// Binary lifting

class TreeAncestor {
    vector<vector<int>> ances;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ances.push_back(parent);
        for (int i = 1; i < 16; i++) {
            vector<int> newAnces;
            vector<int>& prev = ances.back();
            for (int j = 0; j < n; j++) {
                if (prev[j] == -1)    newAnces.push_back(-1);
                else    newAnces.push_back(prev[prev[j]]);
            }
            ances.push_back(newAnces);
        }
    }
    
    int getKthAncestor(int node, int k) {
        int step = 15;
        while (node >= 0 && k > 0) {
            if (k >= 1 << step) {
                k -= 1 << step;
                node = ances[step][node];
            } else {
                step--;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */