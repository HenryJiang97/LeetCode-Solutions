class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int MIN = INT_MAX;
        for (int i= 1; i <= 6; i++) {
            MIN = min(MIN, getRotation(A, B, i));
            MIN = min(MIN, getRotation(B, A, i));
        }
        return MIN == INT_MAX ? -1 : MIN;
    }
    
private:
    int getRotation(vector<int>& A, vector<int>& B, int v) {
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != v && B[i] != v)    return INT_MAX;
            if (A[i] == v)    continue;
            cnt++;
        }
        return cnt;
    }
};