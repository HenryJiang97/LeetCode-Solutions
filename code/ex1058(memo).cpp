class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        unordered_map<int, unordered_map<int, double>> memo;
        double MIN = dfs(prices, target, 0, 0, memo);
        if (MIN == DBL_MAX)    return "-1";
        string s = to_string(MIN);
        return s.substr (0, s.find_first_of ('.', 0) + 4);;
    }
    
private:
    double dfs(vector<string>& prices, int target, int s, int sum, unordered_map<int, unordered_map<int, double>>& memo) {
        if (s == prices.size())
            return sum == target ? 0.0 : DBL_MAX;
        
        if (memo.find(s) != memo.end() && memo[s].find(sum) != memo[s].end())
            return memo[s][sum];
            
        double ret = DBL_MAX;
        vector<int> choices = getCeilAndFloor(prices[s]);
        for (auto cois : choices) {
            double dif = abs((double)cois - stod(prices[s]));
            double diff = dfs(prices, target, s + 1, sum + cois, memo);
            if (diff != DBL_MAX)
                ret = min(ret, diff + dif);
        }
        
        memo[s][sum] = ret;
        return ret;
    }
    
    vector<int> getCeilAndFloor(string price) {
        double p = stod(price);
        return {floor(p), ceil(p)};
    }
};