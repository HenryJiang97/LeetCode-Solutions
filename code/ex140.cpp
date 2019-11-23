class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        memo[""] = {""};
        return backtracking(s, dict, memo);
    }
    
private:
    vector<string> backtracking(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end())    return memo[s];
        vector<string> ret;
        for (int i = 0; i < s.length(); i++) {
            string subs = s.substr(0, i + 1);
            if (dict.find(subs) == dict.end())    continue;
            vector<string> right = backtracking(s.substr(i + 1), dict, memo);
            append(ret, subs, right);
        }
        memo[s] = ret;
        return ret;
    }
    
    void append(vector<string>& ret, string str, vector<string>& list) {
        for (string s : list)
            if (s == "")
                ret.push_back(str);
            else
                ret.push_back(str + " " + s);
    }
};