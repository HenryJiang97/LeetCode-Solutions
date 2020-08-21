class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size(), odd = 0, even = 0;
        for (int a : A) {
            if (a % 2 == 0)    even++;
            else    odd++;
        }
        
        int p1 = 0, p2 = even;
        while (1) {
            while (p1 < even && A[p1] % 2 == 0)    p1++;
            while (p2 < n && A[p2] % 2 == 1)    p2++;
            if (p1 >= even || p2 >= n)    break;
            int temp = A[p1];
            A[p1++] = A[p2];
            A[p2++] = temp;
        }
        
        return A;
    }
};