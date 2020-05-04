class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.length();
        
        int MAX = 0;
        int C = 0, R = 0, O = 0, A = 0, K = 0;

        for (char c : croakOfFrogs) {
            if (c == 'c')    C++;
            if (c == 'r')    R++;
            if (c == 'o')    O++;
            if (c == 'a')    A++;
            if (c == 'k')    K++;
            
            if (!(C >= R && C >= O && O >= A && A >= K))
                return -1;
            
            if (K > 0) {
                C--;    R--;    O--;    A--;    K--;
            }
            
            MAX = max(MAX, C);
        }
        
        return (C == 0 && R == 0 && O == 0 && A == 0 && K == 0) ? MAX : -1;
    }
};