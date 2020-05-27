class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> dislike(N + 1, vector<int>());
        for (auto d : dislikes) {
            dislike[d[0]].push_back(d[1]);
            dislike[d[1]].push_back(d[0]);
        }
        
        vector<int> root(N + 1);
        for (int i = 1; i <= N; i++)    root[i] = i;
        for (int d = 1; d <= N; d++) {
            int rd = find(root, d);
            if (dislike[d].size() > 0) {
                int r0 = find(root, dislike[d][0]);
                for (int i = 1; i < dislike[d].size(); i++) {
                    int ri = find(root, dislike[d][i]);
                    if (ri == rd)    return 0;
                    uni(root, ri, r0);
                }
            }
        }
        
        return 1;
    }
    
private:
    int find(vector<int>& root, int a) {
        if (root[a] != a)
            root[a] = find(root, root[a]);
        return root[a];
    }
    
    void uni(vector<int>& root, int a, int b) {
        int ra = find(root, a), rb = find(root, b);
        if (ra < rb)
            root[ra] = rb;
        else
            root[rb] = ra;
    }
};