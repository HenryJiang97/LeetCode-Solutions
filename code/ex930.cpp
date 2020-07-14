class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        
        int res = 0, sum = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            res += cnt[sum - S];
            cnt[sum]++;
        }
        
        return res;
    }
};