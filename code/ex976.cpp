class Solution {
    bool valid(int a, int b, int c) {
        return b + c > a && a - b < c && a - c < b;
    }
    
public:
    int largestPerimeter(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end(), greater<int>());
        for (int i = 0; i < n - 2; i++) {
            if (valid(A[i], A[i + 1], A[i + 2]))
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};