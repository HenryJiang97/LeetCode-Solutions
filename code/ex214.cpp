class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + " " + rev;
        
        vector<int> nxt = getNext(str);
        
        return rev.substr(0, rev.length() - nxt.back()) + s;
    }
    
private:
    vector<int> getNext(string s) {
        int n = s.length();
        vector<int> nxt{0, 0};
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && s[i] != s[j])    j = nxt[j];
            if (s[i] == s[j])    j++;
            nxt.push_back(j);
        }
        return nxt;
    }
};