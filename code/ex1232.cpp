class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool vertical = 1;
        int x = coordinates[0][0];
        for (auto& coor : coordinates) {
            if (coor[0] != x) {
                vertical = 0;
                break;
            }
        }
        if (vertical)    return 1;
        
        double k = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for (int i = 2; i < coordinates.size(); i++) {
            double kk = (double)(coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
            if (kk != k)    return 0;
            k = kk;
        }
        
        return 1;
    }
};