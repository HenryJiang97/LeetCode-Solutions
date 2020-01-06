class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        else {    // K == 1
            string MAX = S;
            for (int i = 0; i < S.length() - 1; i++) {
                S = S.substr(1) + S[0];
                MAX = min(MAX, S);
            }
            return MAX;
        }
    }
};