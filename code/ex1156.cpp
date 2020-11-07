class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        
        // Get the first and last index of letters in the text
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; i++) {
            first[text[i] - 'a'] = min(first[text[i] - 'a'], i);
            last[text[i] - 'a'] = max(last[text[i] - 'a'], i);
        }
        
        // Global binary search
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (valid(text, first, last, mid))    lo = mid;
            else    hi = mid - 1;
        }
        
        return lo;
    }
    
private:
    bool valid(string text, vector<int>& first, vector<int>& last, int len) {
        map<char, int> map;
        for (int i = 0; i < len; i++)    map[text[i]]++;

        if (map.size() == 1)    return 1;
        if (map.size() == 2) {
            char c1 = (*map.begin()).first, c2 = (*map.rbegin()).first;
            int cnt1 = (*map.begin()).second, cnt2 = (*map.rbegin()).second;
            if (cnt1 == 1 && last[c2 - 'a'] >= len)    return 1;
            if (cnt2 == 1 && last[c1 - 'a'] >= len)    return 1;
        }
        
        for (int hi = len; hi < text.length(); hi++) {
            int lo = hi - len;
            map[text[hi]]++;
            if (--map[text[lo]] == 0)    map.erase(text[lo]);
            
            if (map.size() == 1)    return 1;
            if (map.size() == 2) {
                char c1 = (*map.begin()).first, c2 = (*map.rbegin()).first;
                int cnt1 = (*map.begin()).second, cnt2 = (*map.rbegin()).second;
                if (cnt1 == 1 && (last[c2 - 'a'] > hi || first[c2 - 'a'] <= lo))    return 1;
                if (cnt2 == 1 && (last[c1 - 'a'] >= hi || first[c1 - 'a'] <= lo))    return 1;
            }
        }
        
        return 0;
    }
};