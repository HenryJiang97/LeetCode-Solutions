class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        
        vector<int> res;
        for (int i = n - 1; i >= 1; i--) {
            int maxIdx = findMaxIdx(A, i);
            if (maxIdx == i)    continue;
            if (maxIdx != 0) {
                res.push_back(maxIdx + 1);
                flip(A, maxIdx);
            }
            res.push_back(i + 1);
            flip(A, i);
        }
        
        return res;
    }
    
private:
    int findMaxIdx(vector<int>& A, int hi) {
        int idx = 0, MAX = A[0];
        for (int i = 1; i <= hi; i++) {
            if (A[i] > MAX) {
                idx = i;
                MAX = A[i];
            }
        }
        return idx;
    }
    
    void flip(vector<int>& A, int i) {
        int lo = 0, hi = i;
        while (lo < hi) {
            int temp = A[lo];
            A[lo++] = A[hi];
            A[hi--] = temp;
        }
    }
};