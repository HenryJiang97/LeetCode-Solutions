// 1. Perfect rectangle area == all rectangle area
// 2. Points on four corners of the perfect rectangle will appears once
// 3. All other points will appears twice

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
        
        int area = 0;
        unordered_set<string> set;
        for (auto& rec : rectangles) {
            int cx1 = rec[0], cy1 = rec[1], cx2 = rec[2], cy2 = rec[3];
            x1 = min(x1, cx1);
            y1 = min(y1, cy1);
            x2 = max(x2, cx2);
            y2 = max(y2, cy2);
            area += (cx2 - cx1) * (cy2 - cy1);
            
            // Get four corner point of the rectangle
            string point1 = to_string(cx1) + "," + to_string(cy1);
            string point2 = to_string(cx1) + "," + to_string(cy2);
            string point3 = to_string(cx2) + "," + to_string(cy1);
            string point4 = to_string(cx2) + "," + to_string(cy2);

            if (set.count(point1) > 0)    set.erase(point1);
            else    set.insert(point1);
            if (set.count(point2) > 0)    set.erase(point2);
            else    set.insert(point2);
            if (set.count(point3) > 0)    set.erase(point3);
            else    set.insert(point3);
            if (set.count(point4) > 0)    set.erase(point4);
            else    set.insert(point4);
        }
        
        if (set.count(to_string(x1) + "," + to_string(y1)) == 0
           || set.count(to_string(x2) + "," + to_string(y1)) == 0
           || set.count(to_string(x1) + "," + to_string(y2)) == 0
           || set.count(to_string(x2) + "," + to_string(y2)) == 0
           || set.size() != 4)    return 0;
        
        return (x2 - x1) * (y2 - y1) == area;
    }
};