class Solution {
    int n;
    bool sign = 0;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        sort(tickets.begin(), tickets.end(), [&](vector<string>& a, vector<string>& b) {return a[1] < b[1];});
        
        vector<string> res{"JFK"};
        vector<bool> visited(n);
        dfs(tickets, visited, res, "JFK");
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& res, string cur) {
        if (res.size() == n + 1) {
            sign = 1;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] || tickets[i][0] != cur)    continue;
            visited[i] = 1;
            res.push_back(tickets[i][1]);
            dfs(tickets, visited, res, tickets[i][1]);
            if (sign)    return;
            res.pop_back();
            visited[i] = 0;
        }
    }
};