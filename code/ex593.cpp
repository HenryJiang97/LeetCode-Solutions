class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double d12 = getDistance(p1, p2);    if (d12 == 0)    return 0;
        double d13 = getDistance(p1, p3);    if (d13 == 0)    return 0;
        double d14 = getDistance(p1, p4);    if (d14 == 0)    return 0;
        double d23 = getDistance(p2, p3);    if (d23 == 0)    return 0;
        double d24 = getDistance(p2, p4);    if (d24 == 0)    return 0;
        double d34 = getDistance(p3, p4);    if (d34 == 0)    return 0;
        
        if (d12 != d34 || d13 != d24 || d14 != d23)    return 0;
        return d12 == d13 || d12 == d14 || d13 == d14;
    }
    
private:
    double getDistance(vector<int>& p1, vector<int>& p2) {
        return sqrt((double)(p1[0] - p2[0]) * (p1[0] - p2[0]) + (double)(p1[1] - p2[1]) * (p1[1] - p2[1]));
    }
};