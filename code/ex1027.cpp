// Dynamic Programming

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        
        // Diff, Last ending index, Length
        unordered_map<int, unordered_map<int, int>> m;
        int MAX = 2;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                if (m.find(diff) == m.end()) {
                    m[diff][i] = 2;
                } else {
                    if (m[diff].find(j) != m[diff].end()) {
                        m[diff][i] = m[diff][j] + 1;
                        MAX = max(MAX, m[diff][i]);
                    } else {
                        m[diff][i] = 2;
                    }
                }
            }
        }
        
        return MAX;
    }
};