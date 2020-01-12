class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<int> rec1 = {A, B, C, D}, rec2 = {E, F, G, H};
        if (!isRectangleOverlap(rec1, rec2))    return area(rec1) + area(rec2);
        else {
            int x = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
            int y = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
            return area(rec1) - x * y + area(rec2);
        }
    }
    
private:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int blx1 = rec1[0], bly1 = rec1[1], trx1 = rec1[2], try1 = rec1[3];
        int blx2 = rec2[0], bly2 = rec2[1], trx2 = rec2[2], try2 = rec2[3];
        return !(blx2 >= trx1 || blx1 >= trx2 || bly1 >= try2 || bly2 >= try1);
    }
    
    int area(vector<int>& rec) {
        return (rec[2] - rec[0]) * (rec[3] - rec[1]);
    }
};