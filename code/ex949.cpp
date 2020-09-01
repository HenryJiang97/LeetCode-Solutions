class Solution {
    string MAX = "";
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<bool> visited(4);
        dfs(A, visited, 0, "");
        if (MAX == "")    return "";
        MAX.insert(MAX.begin() + 2, ':');
        return MAX;
    }
    
private:
    void dfs(vector<int>& A, vector<bool>& visited, int s, string cur) {
        if (s == 4) {
            if (valid(cur))    MAX = max(MAX, cur);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            if (visited[i])    continue;
            visited[i] = 1;
            dfs(A, visited, s + 1, cur + to_string(A[i]));
            visited[i] = 0;
        }
    }
    
    bool valid(string s) {
        int d1 = s[0] - '0', d2 = s[1] - '0', d3 = s[2] - '0', d4 = s[3] - '0';
        if (d1 > 2 || (d1 == 2 && d2 >= 4))    return 0;
        return d3 <= 5;
    }
};