class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        string res = "";
        
        int p = 0;
        while (p < n) {
            // Reverse k chars
            string sub = s.substr(p, k);
            reverse(sub.begin(), sub.end());
            res += sub;
            p += k;
            
            if (p >= n)    break;
                
            // k chars in original order
            sub = s.substr(p, k);
            res += sub;
            p += k;
        }
        
        return res;
    }
};