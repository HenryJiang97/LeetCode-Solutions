class Solution {
public:
    vector<vector<int>> generate(int n) {
        if (n == 0)    return {};
        vector<vector<int>> tri;
        tri.push_back(vector<int>{1});
        for (int i = 1; i < n; i++) {
            vector<int> cur{1};
            vector<int> prev = tri.back();
            for (int j = 0; j < i - 1; j++) {
                cur.push_back(prev[j] + prev[j + 1]);
            }
            cur.push_back(1);
            tri.push_back(cur);
        }
        return tri;
    }
};