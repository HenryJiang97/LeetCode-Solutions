class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double xc = (double)(x1 + x2) / 2, yc = (double)(y1 + y2) / 2;    // Rectangle center
        
        // Diagonal
        double dis = radius + sqrt((xc - x1) * (xc - x1) + (yc - y1) * (yc - y1));
        if (dis < sqrt((xc - x_center) * (xc - x_center) + (yc - y_center) * (yc - y_center))) {
            return 0;
        }
        
        if ((xc - x_center <= radius + (xc - x1)) && (x_center - xc <= radius + (xc - x1))
           && (yc - y_center <= radius + (yc - y1)) && (y_center - yc <= radius + (yc - y1)))
            return 1;
        return 0;
    }
};