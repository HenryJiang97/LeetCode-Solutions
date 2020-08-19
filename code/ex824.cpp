class Solution {
    vector<char> v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    unordered_set<char> vowels;
    
    vector<string> split(string s) {
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
    
    string getGoatWord(string s, int idx) {
        if (vowels.count(s[0]) == 0) {
            s.push_back(s[0]);
            s.erase(s.begin());
        }
        s += "ma" + string(idx, 'a');
        return s;
    }
    
public:
    string toGoatLatin(string S) {
        vowels = unordered_set<char>(v.begin(), v.end());
        vector<string> words = split(S);
        string s = "";
        for (int i = 0; i < words.size(); i++) {
            s += getGoatWord(words[i], i + 1);
            if (i != words.size() - 1)    s += ' ';
        }
        return s;
    }
};