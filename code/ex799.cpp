class Solution {
public:
    double champagneTower(int poured, int row, int col) {
        if (row == 0)    return min(1, poured);
        vector<double> prev{(double)poured};
                
        for (int i = 1; i <= row; i++) {
            vector<double> cur;
            for (int j = 0; j < i; j++) {
                double left = j - 1 >= 0 ? max(0.0, (prev[j - 1] - 1.0)) / 2 : 0;
                double right = max(0.0, (prev[j] - 1.0)) / 2;
                cur.push_back(left + right);
            }
            cur.push_back(max(0.0, (prev.back() - 1)) / 2);
            prev = cur;
        }
        
        return min(prev[col], 1.0);
    }
};