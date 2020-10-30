class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)    return 0;
        
        int has = -prices[0];
        int no = 0, no1 = INT_MIN / 2;
        for (int i = 1; i < n; i++) {
            int hasBkp = has;
            int noBkp = no, noBkp1 = no1;
            has = max(max(hasBkp, -prices[i]), i >= 2 ? noBkp1 - prices[i] : INT_MIN / 2);
            no = max(noBkp, hasBkp + prices[i]);
            no1 = noBkp;
        }
        
        return no;
    }
};