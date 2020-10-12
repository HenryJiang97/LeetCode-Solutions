class Solution {
public:
    bool buddyStrings(string A, string B) {
        int na = A.length(), nb = B.length();
        if (na != nb)    return 0;
        
        int diff = 0, d1 = -1, d2 = -1;
        bool hasDup = 0;
        unordered_set<char> visited;
        for (int i = 0; i < na; i++) {
            if (A[i] != B[i]) {
                diff++;
                if (d1 == -1)    d1 = i;
                else    d2 = i;
            }
            if (visited.count(A[i]) > 0)    hasDup = 1;
            visited.insert(A[i]);
        }
        
        return diff == 2 && A[d1] == B[d2] && A[d2] == B[d1] || diff == 0 && hasDup;
    }
};