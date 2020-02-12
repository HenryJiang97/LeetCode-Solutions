class Solution {
public:
    vector<string> generatePalindromes(string s) {
        // Same as ex266
        unordered_map<char, int> dict;
        for (char c : s)    dict[c]++;
        int cnt = 0;
        for (auto entry : dict)
            if (entry.second % 2 == 1)    cnt++;
        if (cnt > 1)    return {};
        
        // Get char candidates for first half the string
        vector<char> chrs;
        char center = ' ';
        for (auto entry : dict) {
            if (entry.second % 2 == 1)    center = entry.first;
            for (int i = 0; i < entry.second / 2; i++)
                chrs.push_back(entry.first);
        }
        sort(chrs.begin(), chrs.end());
        
        // Backtracking
        vector<string> res;
        vector<bool> visited(chrs.size());
        backtracking(res, chrs, visited, "", center);
        
        return res;
    }
    
private:
    void backtracking(vector<string>& res, vector<char>& chrs, vector<bool>& visited, string cur, char center) {
        if (cur.length() == chrs.size()) {
            res.push_back(buildString(cur, center));
            return;
        }
        
        for (int i = 0; i < chrs.size(); i++) {
            if (visited[i])    continue;
            if (i > 0 && chrs[i] == chrs[i - 1] && !visited[i - 1])    continue;
            visited[i] = 1;
            backtracking(res, chrs, visited, cur + chrs[i], center);
            visited[i] = 0;
        }
    }
    
    string buildString(string s, char center) {
        int n = s.length();
        if (center != ' ')    s.push_back(center);
        for (int i = n - 1; i >= 0; i--)
            s.push_back(s[i]);
        return s;
    }
};