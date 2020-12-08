class Solution {
    unordered_set<string> visited;
    int MAX = 0;
public:
    int maxUniqueSplit(string s) {
        dfs(s, 0, 0);
        return MAX;
    }
    
private:
    void dfs(string s, int cur, int cnt) {
        if (cur >= s.length()) {
            MAX = max(MAX, cnt);
            return;
        }
        
        string S = "";
        for (int i = cur; i < s.length(); i++) {
            S += s[i];
            if (visited.count(S))    continue;
            visited.insert(S);
            dfs(s, i + 1, cnt + 1);
            visited.erase(S);
        }
    }
};