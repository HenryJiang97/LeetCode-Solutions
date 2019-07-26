class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res(2);
        int end = (int)sqrt(area);
        while (end <= area) {
            if (area % end == 0 && area / end <= end) {
                res[0] = end;    res[1] = area / end;
                break;
            }
            end++;
        }
        return res;
    }
};