// Search by diagonal

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])    return a[0] < b[0];
        else    return a[1] < b[1];
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();    if (n == 0)    return 0;
        // Sort by x in ascending order, if have same x, sort by y in ascending order
        sort(points.begin(), points.end(), cmp());  
        
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
                    MIN = min(MIN, abs(y2 - y1) * (x2 - x1));
            }
        }
        
        return MIN == INT_MAX ? 0 : MIN;
    }
};