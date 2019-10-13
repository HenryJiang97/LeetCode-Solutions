class Solution {
    int n;
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        n = A.size();
        
        int rotateToA1 = getRotationToA(A, B, A[0]);
        int rotateToA2 = getRotationToA(A, B, B[0]);
        int rotateToB1 = getRotationToB(A, B, B[0]);
        int rotateToB2 = getRotationToB(A, B, A[0]);

        int MIN = INT_MAX;
        if (rotateToA1 != -1)    MIN = min(MIN, rotateToA1);
        if (rotateToA2 != -1)    MIN = min(MIN, rotateToA2);
        if (rotateToB1 != -1)    MIN = min(MIN, rotateToB1);
        if (rotateToB2 != -1)    MIN = min(MIN, rotateToB2);
    
        return MIN == INT_MAX ? -1 : MIN;
    }
    
private:
    int getRotationToA(vector<int>& A, vector<int>& B, int target) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == target)    continue;
            if (B[i] == target)    cnt++;
            else    return -1;
        }
        return cnt;
    }
    
    int getRotationToB(vector<int>& A, vector<int>& B, int target) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (B[i] == target)    continue;
            if (A[i] == target)    cnt++;
            else    return -1;
        }
        return cnt;
    }
};