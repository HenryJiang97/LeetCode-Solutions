class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for (char move : moves) {
            switch(move) {
                case 'U':
                    i--;    break;
                case 'D':
                    i++;    break;
                case 'L':
                    j--;    break;
                case 'R':
                    j++;    break;
            }
        }
        return i == 0 && j == 0;
    }
};