class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        s += ' ';    cost.push_back(0);
        int res = 0, sum = 0, MAX = 0, cnt = 0;
        char prev = ' ';
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == prev) {
                sum += cost[i];
                MAX = max(MAX, cost[i]);
                cnt++;
            } else {
                if (cnt > 1)    res += sum - MAX;
                prev = c;
                sum = MAX = cost[i];
                cnt = 1;
            }
        }
        return res;
    }
};