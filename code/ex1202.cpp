class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        // Group indexes which can be swapped
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& pair : pairs) {
            uni(parent, pair[0], pair[1]);
        }
        
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(parent, i)].push_back(i);
        }
        
        // Reorder chars
        for (auto& [k, v] : groups) {
            vector<char> cand;
            for (int i : v) {
                cand.push_back(s[i]);
            }
            sort(cand.begin(), cand.end());
            int p = 0;
            for (int i : v) {
                s[i] = cand[p++];
            }
        }
        
        return s;
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