class Solution {
    unordered_map<int, int> group;
    int cnt = 0;
    int last = -1;
    int m;
    
public:
    int findLatestStep(vector<int>& arr, int m) {
        this->m = m;
        int n = arr.size();
        
        int step = 1;
        vector<int> parent(n, -1), cur(n);
        for (int a : arr) {
            int i = a - 1;
            cur[i] = 1;
            parent[i] = i;
            
            group[i] = 1;
            if (group[i] == m)    cnt++;

            if (i - 1 >= 0 && cur[i - 1] == 1) {
                uni(parent, i - 1, i);
            }
            if (i + 1 < n && cur[i + 1] == 1) {
                uni(parent, i, i + 1);
            }
            if (cnt > 0)    last = step;
            step++;
        }
        
        return last;
    }
    
private:
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra < rb) {
            parent[rb] = ra;
            if (group[ra] == m)    cnt--;
            group[ra] += group[rb];
            if (group[rb] == m)    cnt--;
            group.erase(rb);
            if (group[ra] == m)    cnt++;
        } else {
            parent[ra] = rb;
            if (group[rb] == m)    cnt--;
            group[rb] += group[ra];
            if (group[ra] == m)    cnt--;
            group.erase(ra);
            if (group[rb] == m)    cnt++;
        }
    }
};

