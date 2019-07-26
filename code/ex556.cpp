// Next permutation
// 1. From right to left, find the first digit which violates the increasing trend, name as a
// 2. From right to left, find the first digit which is larger than a, name as b
// 3. Swap a and b
// 4. Reverse all digits to the right of a index

class Solution {
public:
    int nextGreaterElement(int n) {
        string N = to_string(n);
        n = N.length();    if (n < 2)    return -1;
        
        // Get a index
        int a_idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (N[i] < N[i + 1]) {
                a_idx = i;
                break;
            }
        }
        if (a_idx == -1)    return -1;
        
        // Get b index
        int b_idx = a_idx;
        for (int i = n - 1; i >= 0; i--) {
            if (N[i] > N[a_idx]) {
                b_idx = i;
                break;
            }
        }
        if (b_idx == a_idx)    return -1;
        
        // Swap digit of a index and b index
        swap(N, a_idx, b_idx);
        
        // Reverse all digits to the right of a index
        int lo = a_idx + 1, hi = n - 1;
        while (lo < hi) {
            swap(N, lo, hi);
            lo++;    hi--;
        }
        
        if (stol(N) > pow(2, 31) - 1)    return -1;
        
        return stoi(N);
    }
    
private:
    void swap(string& s, int idx1, int idx2) {
        char temp = s[idx1];    s[idx1] = s[idx2];    s[idx2] = temp;
    }
};