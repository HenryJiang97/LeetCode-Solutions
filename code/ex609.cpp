class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (string p : paths) {
            vector<string> sarr = splitArr(p);
            string path = sarr[0];
            for (int i = 1; i < sarr.size(); i++) {
                auto fileArr = splitFileName(sarr[i]);
                string content = fileArr[0];
                string name = fileArr[1];
                string fullPath = path + '/' + name;
                m[content].push_back(fullPath);
            }
        }
        
        // Get results
        vector<vector<string>> groups;
        for (auto& [k, v] : m) {
            if (v.size() < 2)    continue;
            vector<string> group;
            for (string s : v) {
                group.push_back(s);
            }
            groups.push_back(group);
        }
        return groups;
    }
    
private:
    vector<string> splitArr(string s) {
        s += ' ';
        vector<string> res;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                res.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return res;
    }
    
    vector<string> splitFileName(string s) {    // {content, name}
        string content = "", name = "";
        int i = 0;
        while (s[i] != '(')    {name += s[i];    i++;}
        i++;
        while (s[i] != ')')    {content += s[i];    i++;}
        return {content, name};
    }
};