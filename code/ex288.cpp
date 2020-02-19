class ValidWordAbbr {
    unordered_map<string, string> dict;
    
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string d : dictionary) {
            string abbr = getAbbreviation(d);
            dict[abbr] = dict.count(abbr) > 0 && dict[abbr] != d ? "" : d;
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbreviation(word);
        return dict.find(abbr) == dict.end() || dict[abbr] == word; 
    }

private:
    string getAbbreviation(string s) {
        int n = s.length();
        if (n <= 2)    return s;
        return s[0] + to_string(n - 2) + s[n - 1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */