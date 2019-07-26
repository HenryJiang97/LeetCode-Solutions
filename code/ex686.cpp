class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = B.length();

        int repete = 1;
        string temp = A;
        while (A.length() < n)    {A += temp;    repete++;}
        
        // Judge if result == repete
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[0])    continue;
            if (A.substr(i, n) == B)    return repete;
        }
        
        // Judge if result == repete + 1    
        repete++;    A += A;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[0])    continue;
            if (A.substr(i, n) == B)    return repete;
        }
        
        return -1;
    }
};