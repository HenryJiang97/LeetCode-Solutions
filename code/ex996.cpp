class Solution {
    unordered_map<int, int> cnt;
    unordered_map<int, unordered_set<int>> squareful;
    
public:
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        
        for (int a : A)    cnt[a]++;
        
        for (auto& e1 : cnt) {
            for (auto& e2 : cnt) {
                int i = e1.first, j = e2.first;
                if ((int)sqrt(i + j) * (int)sqrt(i + j) == i + j) {
                    squareful[i].insert(j);
                }
            }
        }
        
        int res = 0;
        for (auto e : cnt) {
            cnt[e.first]--;
            dfs(e.first, n - 1, res);
            cnt[e.first]++;
        }
        
        return res;
    }
    
private:
    void dfs(int cur, int remain, int& res) {
        if (remain == 0) {
            res++;
            return;
        }
        
        for (int nxt : squareful[cur]) {
            if (cnt[nxt] > 0) {
                cnt[nxt]--;
                dfs(nxt, remain - 1, res);
                cnt[nxt]++;
            }
        }
    }
};