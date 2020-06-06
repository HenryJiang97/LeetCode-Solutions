class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        int n = people.size();
        vector<vector<int>> res(n, vector<int>(2, INT_MAX));
        for (auto& p : people) {
            int h = p[0], k = p[1];
            int i = 0, cnt = 0;
            while (cnt < k) {
                if (res[i][0] >= h)    cnt++;
                i++;
            }
            while (res[i][0] != INT_MAX)    i++;
            res[i][0] = h;    res[i][1] = k;
        }
        return res;
    }
};