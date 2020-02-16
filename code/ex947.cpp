class Solution {
    const int n = 10000;

public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> parent;

        // Union
        for (auto& stone : stones) {
            int r = stone[0], c = stone[1];
            int hcode = r * n + c;
            parent[hcode] = hcode;
            
            if (row.find(r) == row.end())    row[r] = hcode;
            else    uni(parent, row[r], hcode);
            if (col.find(c) == col.end())    col[c] = hcode;
            else    uni(parent, col[c], hcode);
        }
        
        // Find groups
        unordered_map<int, int> cnt;
        for (auto& stone : stones) {
            int hcode = stone[0] * n + stone[1];
            cnt[find(parent, hcode)]++;
        }
        
        // Get moves
        int res = 0;
        for (auto entry : cnt)
            res += entry.second - 1;
        return res;
    }
    
private:
    void uni(unordered_map<int, int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    int find(unordered_map<int, int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
};