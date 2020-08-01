class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size(), carry = 0;
        for (int i = n - 1; i >= 0 || K > 0; i--) {
            int a = i >= 0 ? A[i] : 0;
            int b = K % 10;    K /= 10;
            int val = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            if (i >= 0)    A[i] = val;
            else    A.insert(A.begin(), val);
        }
        if (carry > 0)    A.insert(A.begin(), carry);
        return A;
    }
};