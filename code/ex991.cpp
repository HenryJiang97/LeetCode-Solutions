class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y)    return X - Y;
        int step = 0;
        while (Y > X) {
            if (Y % 2 == 1) {
                Y++;
                step++;
            }
            Y /= 2;
            step++;
        }
        return step + X - Y;
    }
};