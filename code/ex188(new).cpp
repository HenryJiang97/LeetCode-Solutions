class Solution {
    int n;
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();    if (n <= 1)    return 0;
        int lo = 0, hi = *max_element(prices.begin(), prices.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (stockWithTransFee(prices, mid)[1] > k)    lo = mid + 1;
            else    hi = mid;
        }
        return stockWithTransFee(prices, hi)[0] + hi * k;
    }

private:
    vector<int> stockWithTransFee(vector<int>& prices, int fee) {
        vector<int> hasStock(n, INT_MIN / 2);
        vector<int> noStock(n, INT_MIN / 2);
        hasStock[0] = -prices[0] - fee;
        noStock[0] = 0;
        int cntSold = 0, cntBuy = 1;
        
        for (int i = 1; i < n; i++) {
            if (hasStock[i - 1] + prices[i] > noStock[i - 1]) {
                noStock[i] = hasStock[i - 1] + prices[i];
                cntSold = cntBuy + 1;
            } else {
                noStock[i] = noStock[i - 1];
            }
            
            if (noStock[i - 1] - prices[i] - fee > hasStock[i - 1]) {
                hasStock[i] = noStock[i - 1] - prices[i] - fee;
                cntBuy = cntSold;
            } else {
                hasStock[i] = hasStock[i - 1];
            }
        }
        
        return {noStock[n - 1], cntSold};
    }
};