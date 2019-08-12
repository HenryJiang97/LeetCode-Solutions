class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size(), nb = B.size();
        
        vector<vector<int>> res;
        
        int p1 = 0, p2 = 0;
        while (p1 < na && p2 < nb) {
            // When no common parts between current two intervals, move forward
            if (A[p1][1] < B[p2][0])    {p1++;    continue;}
            if (B[p2][1] < A[p1][0])    {p2++;    continue;}
            
            res.push_back({max(A[p1][0], B[p2][0]), min(A[p1][1], B[p2][1])});
            
            // Move p1 and p2 accordingly
            if (A[p1][1] < B[p2][1])    p1++;
            else    p2++;
        }
        
        return res;
    }
};