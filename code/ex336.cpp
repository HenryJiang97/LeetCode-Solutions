class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            map[word] = i;
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int l = 1; l <= word.length(); l++) {
                string left = word.substr(0, l);
                string right = word.substr(l);
                if (map.count(left) > 0 && isPalindrome(right) && map[left] != i) {
                    res.push_back({i, map[left]});
                }
                if (map.count(right) > 0 && isPalindrome(left) && map[right] != i) {
                    res.push_back({map[right], i});
                }
            }
        }
        
        if (map.count("") > 0) {
            for (int i = 0; i < words.size(); i++) {
                if (map[""] != i && isPalindrome(words[i])) {
                    res.push_back({i, map[""]});
                }
            }
        }
        
        return res;
    }
    
private:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--])    return 0;
        }
        return 1;
    }
};