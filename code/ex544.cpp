class Solution {
public:
    string findContestMatch(int n) {
        vector<string> teams(n);
        for (int i = 1; i <= n; i++)
            teams[i - 1] = to_string(i);
        
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                teams[i] = "(" + teams[i] + "," + teams[n - i - 1] + ")";
            }
            n /= 2;
        }
        
        return teams[0];
    }
};