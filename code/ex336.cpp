#define all(x) (x).begin(), (x).end()

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            reverse(all(word));
            map[word] = i;
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            for (int j = 0; j < word.length(); j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                if (map.find(left) != map.end() && isPalindrome(right) && map[left] != i)
                    res.push_back({i, map[left]});
                
                if (map.find(right) != map.end() && isPalindrome(left) && map[right] != i)
                    res.push_back({map[right], i});
            }
        }
        
        if (map.find("") != map.end()) {
            for (string word : words) {
                if (isPalindrome(word) && word != "")
                    res.push_back({map[""], map[word]});
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