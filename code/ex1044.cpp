// Binary Search + Rolling Hash

class Solution {
    long mod = pow(2, 32);
    
public:
    string longestDupSubstring(string S) {
        int n = S.length();
        
        // Binary search for the longest length of duplicate substring
        string res = "";
        int lo = 1, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            int start = findString(S, mid);
            if (start != -1) {
                lo = mid;
                res = S.substr(start, mid);
            }
            else    hi = mid - 1;
        }
        
        return res;
    }
    
private:
    // Rolling hash to find the duplicated substring with certain length
    int findString(string s, int len) {
        int n = s.length();
        
        unordered_set<long> set;
        long hash = 0;
        
        // Get the initial hash
        for (int i = 0; i < len; ++i)    hash = (hash * 26 + (s[i] - 'a')) % mod;
        set.insert(hash);
        
        // Get exponential
        long expo = 1;
        for (int i = 0; i < len; i++)    expo = (expo * 26) % mod;
        
        // Sliding window to the right
        for (int i = 1; i <= n - len; i++) {
            hash = (hash * 26 - (s[i - 1] - 'a') * expo % mod + mod) % mod;
            hash = (hash + (s[i + len - 1] - 'a')) % mod;
            if (set.find(hash) != set.end())    return i;
            set.insert(hash);
        }
        
        return -1;
    }
};