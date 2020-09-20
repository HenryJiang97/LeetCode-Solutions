class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(), res = 0;
        
        unordered_map<int, int> less;
        unordered_map<int, int> lessEqual;
        for(int l = 0, le = 0, i = 0; i < n; i++) {
            less[A[i]]++;
            lessEqual[A[i]]++;
            
            while (less.size() >= K) {
                if (--less[A[l]] == 0)    less.erase(A[l]);
                l++;
            }
            
            while (lessEqual.size() > K) {
                if (--lessEqual[A[le]] == 0)    lessEqual.erase(A[le]);
                le++;
            }
            
            res += l - le;
        }
        
        return res;
    }
};