class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0][0], MAX = arrays[0].back();
        int dis = 0;
        for (int i = 1; i < arrays.size(); i++) {
            dis = max(dis, arrays[i].back() - MIN);
            dis = max(dis, MAX - arrays[i][0]);
            
            MIN = min(MIN, arrays[i][0]);
            MAX = max(MAX, arrays[i].back());
        }
        return dis;
    }
};