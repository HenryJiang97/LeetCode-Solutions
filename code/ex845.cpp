// Two pointers

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();    if (n < 3)    return 0;
        
        int MAX = 0;
        int start = 0, end = 0;
        
        while (start < n) {
            // Find the start
            if (start + 1 >= n || A[start] >= A[start + 1]) {
                start++;
                continue;
            }
            end = start;
            
            // Find peak
            while (end + 1 < n && A[end] < A[end + 1])    end++;
            
            // Find the end point
            if (end + 1 < n && A[end] > A[end + 1]) {
                while (end + 1 < n && A[end] > A[end + 1])    end++;
                MAX = max(MAX, end - start + 1);
            }
          
            start = end;
        }
        
        return MAX;
    }
};