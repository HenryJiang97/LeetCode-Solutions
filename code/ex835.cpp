class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        
        unordered_set<int> setb;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (B[i][j] == 1)
                    setb.insert(i * n + j);
            }
        }
        
        vector<vector<int>> arra;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1)
                    arra.push_back({i, j});
            }
        }
        
        int MAX = 0;
        for (int di = -n; di <= n; di++) {
            for (int dj = -n; dj <= n; dj++) {
                int cnt = 0;
                for (auto& a : arra) {
                    int i = a[0], j = a[1];
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n || setb.count(ni * n + nj) == 0)
                        continue;
                    cnt++;
                }
                MAX = max(MAX, cnt);
            }
        }
        
        return MAX;
    }
};