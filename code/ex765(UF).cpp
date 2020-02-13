// Union find

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i += 2) {
            parent[i] = i;
            parent[i + 1] = i;
        }
        
        // Union
        for (int i = 0; i < n; i += 2)
            uni(parent, row[i], row[i + 1]);
        
        // Get groups
        unordered_map<int, int> groups;
        for (int i = 0; i < n; i++)
            groups[find(parent, i)]++;
        
        // Get swaps needed for each group
        int cnt = 0;
        for (auto entry : groups)
            cnt += entry.second / 2 - 1;
        
        return cnt;
    }
    
private:
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