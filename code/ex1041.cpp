class Solution {
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    bool isRobotBounded(string instructions) {
        int i = 0, j = 0, d = 0;
        for (char c : instructions) {
            switch (c) {
                case 'G':
                    i += dir[d][0];
                    j += dir[d][1];
                    break;
                case 'L':
                    d = (d - 1 + 4) % 4;
                    break;
                case 'R':
                    d = (d + 1) % 4;
            }
        }
        return i == 0 && j == 0 || d != 0;
    }
};