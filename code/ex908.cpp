class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int n = A.size();    if (n <= 1)    return 0;
        int MIN = A[0], MAX = A[0];
        for (int a : A) {MIN = min(MIN, a); MAX = max(MAX, a);}
        MIN += K; MAX -= K;
        return MIN >= MAX ? 0 : MAX - MIN;
    }
};