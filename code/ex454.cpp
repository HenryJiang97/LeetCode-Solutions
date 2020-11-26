class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab;
        for (int a : A) {
            for (int b : B) {
                ab[a + b]++;
            }
        }
        
        int cnt = 0;
        for (int c : C) {
            for (int d : D) {
                int target = -c - d;
                cnt += ab[target];
            }
        }
        
        return cnt;
    }
};