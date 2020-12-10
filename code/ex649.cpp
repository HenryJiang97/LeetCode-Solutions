class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> R, D;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')    R.push(i);
            else    D.push(i);
        }

        // Kill the next closest rival
        while (!R.empty() && !D.empty()) {
            int rout = R.front(), dout = D.front();
            R.pop();    D.pop();
            rout < dout ? R.push(rout + n) : D.push(dout + n);
        }
        
        return R.empty() ? "Dire" : "Radiant";
    }
};