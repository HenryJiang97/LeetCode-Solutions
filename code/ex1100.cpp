class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int n = S.length();    if (K > n)    return 0;
        
        unordered_map<char, int> cnt;
        
        int res = 0;
        // Add first K char to the cnt map
        for (int i = 0; i < K; i++) {
            cnt[S[i]]++;
        }
        if (cnt.size() == K)    res++;
        
        // Slide sliding window
        int lo = 0, hi = K;
        while (hi < n) {
            cnt[S[hi++]]++;
            if (--cnt[S[lo]] == 0)    cnt.erase(S[lo]);
            lo++;
            
            if (cnt.size() == K)    res++;
        }
        
        return res;
    }
};