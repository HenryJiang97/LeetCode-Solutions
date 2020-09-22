class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> groups;
        for (string str : strs) {
            groups[getCode(str)].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& [k, v] : groups) {
            res.push_back(v);
        }
        return res;
    }
    
private:
    string getCode(string s) {
        string code = string(26, '0');
        for (char c : s) {
            code[c - 'a']++;
        }
        return code;
    }
};