// Search by diagonal

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();    if (n == 0)    return 0;
        
        // Generate a hash map for each point
        unordered_map<int, unordered_set<int>> map;
        for (auto point : points)    map[point[0]].insert(point[1]);
        
        // Loop through each point by diagonal
        int MIN = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                if (x1 == x2 || y1 == y2)    continue;
                
                if (map[x1].find(y2) != map[x1].end() && map[x2].find(y1) != map[x2].end())
                    MIN = min(MIN, abs((y2 - y1) * (x2 - x1)));
            }
        }
        
        return MIN == INT_MAX ? 0 : MIN;
    }
};