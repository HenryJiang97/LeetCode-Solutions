class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int score = 0, lo = 0, hi = tokens.size() - 1;
        while (lo <= hi) {
            if (P < tokens[lo]) {
                if (score >= 1 && lo + 1 <= hi && P + tokens[hi] >= tokens[lo]) {
                    P += tokens[hi--];
                    score--;
                } else {
                    break;
                }                
            }
            if (lo <= hi && P >= tokens[lo]) {
                P -= tokens[lo++];
                score++;
            }
        }
        return score;
    }
};