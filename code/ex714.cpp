class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hasStock = -prices[0], noStock = 0;
        for (int i = 1; i < n; i++) {
            int bkpNoStock = noStock, bkpHasStock = hasStock;
            noStock = max(noStock, bkpHasStock + prices[i] - fee);
            hasStock = max(hasStock, bkpNoStock - prices[i]);
        }
        return noStock;
    }
};