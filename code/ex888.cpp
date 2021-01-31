class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int diff = (suma - sumb) / 2;
        unordered_set<int> setb(B.begin(), B.end());
        for (int a : A) {
            if (setb.count(a - diff) > 0) {
                return {a, a - diff};
            }
        }
        return {-1, -1};
    }
};